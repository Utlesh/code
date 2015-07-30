#include <iostream>
using namespace std;
#include <stdio.h>
#include <malloc.h>

struct node{
 int data;
 node *next;
};

void removeLoop(node *,node *);

void detectAndRemoveLoop(node *head)
{
  node *slow,*fast;
  slow = fast = head;
  while(fast&&fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast)
    {
    	cout<<"loop detected\n";
        removeLoop(slow,head);
        break;
    }
  }
}

void removeLoop(node *slow,node *head)
{
	node *ptr1,*ptr2;
	int k = 1;
	ptr1 = ptr2 = slow;
	while(ptr1->next != ptr2)
	{
		ptr1 = ptr1->next;
		++k;
	}
    
    ptr1 = ptr2 = head;
	for(int i = 0; i<k ; ++i)
	{
		ptr1 = ptr1->next;
	}

    while(ptr1 != ptr2)
    {
    	ptr1 = ptr1->next;
    	ptr2 = ptr2->next;
    }

    ptr1 = ptr1->next;
    while(ptr1->next != ptr2)
    {
    	ptr1 = ptr1->next;
    }

    ptr1->next = NULL;
}

void push(struct node** head_ref, int new_data)
{
    
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
 
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}

void printList(node *head)
{
	while(head)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<"\n";
}

int main()
{
    struct node* head = NULL;
 
    push(&head, 10);
    push(&head, 4);
    push(&head, 15);
    push(&head, 20);
    push(&head, 50);
 
    head->next->next->next->next->next = head->next->next;
 
    detectAndRemoveLoop(head);
 
    printf("Linked List after removing loop \n");
    printList(head);
    getchar();
    return 0;
}
#include <iostream>
using namespace std;

struct node{
 int data;
 node *right;
};


void createLinklist(node **root)
{
	int num,x;
	cout<<"How many nodes r there in linklist:\n";
	cin>>num;
        node *temp;
 
     	*root = new node;
     	cin>>x;
     	(*root)->data = x;
     	(*root)->right = NULL;
        temp = *root;

     	while(num>1)
     	{
     	  num--;	
        node *temp1 = new node;
     	  cin>>x;
     	  temp1->data = x;
     	  temp1->right = NULL;
     	  temp->right = temp1;
     	  temp = temp1; 
     	}
}

void mergesortUTIL(node *ptr,node **head,node **tail)
{
  node *slow,*fast,*prev;
  
  if(!ptr && !(ptr->right))
  { 
    *head = ptr;
    *tail = NULL;
    return ;
  }
else
{
  fast = slow = ptr;
  while(fast && fast->right)
  { 
    prev = slow;
    slow = slow->right;
    fast = fast->right->right;
  }
}

  if(!fast)
    {
      *tail = slow;
       prev->right = NULL;
    }
   else
   {
      *tail = slow->right;
      slow->right = NULL;
   }

      *head = ptr;
}

node *sortLinkList(node *head,node *tail)
{
  if(!head)
    return tail;
  else if(!tail)
    return head;

  node *result = NULL;
  if(head->data<tail->data)
  {
    result = head;
    result->right = sortLinkList(head->right,tail);
  }
  else
  {
    result = tail;
    result->right = sortLinkList(head,tail->right);
  }

  return result;

}

void mergesort(node **ptr)
{
  node *head,*tail,*a = *ptr;
  head = tail = NULL;

  if(!(*ptr) || !((*ptr)->right))
    return ;

  mergesortUTIL(a,&head,&tail);
  mergesort(&head);
  mergesort(&tail);
  *ptr = sortLinkList(head,tail);

}

int main()
{
  node *ptr1 = NULL;
  createLinklist(&ptr1);
  node *temp = ptr1;
 
  while(temp)
  {
  	cout<<temp->data<<" ";
  	temp = temp->right;
  }
  cout<<"\n";
  mergesort(&ptr1);
  temp = ptr1;
  while(temp)
  {
    cout<<temp->data<<" ";
    temp = temp->right;
  }


 cout<<"\n";
 return 0;
}

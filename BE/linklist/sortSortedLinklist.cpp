#include <iostream>
using namespace std;

struct node{
 int data;
 node *right;
};

node  *mergeLinklist(node *ptr1,node *ptr2)
{
	node *result = NULL;

	if(ptr1 == NULL)
		return ptr2;
	if(ptr2 == NULL)
		return ptr1;


    if(ptr1->data<ptr2->data)
	{
	   result = ptr1;
	   result->right = mergeLinklist(ptr1->right,ptr2);
	}
	else if(ptr1->data>=ptr2->data)
	{
	   result = ptr2;
	   result->right = mergeLinklist(ptr1,ptr2->right);
	}

    return result;

}

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

 node *ptr2 = NULL;
 createLinklist(&ptr2);
 temp = ptr2;
 while(temp)
  {
 	cout<<temp->data<<" ";
 	temp = temp->right;
  }

 cout<<"\n";

 node *root = mergeLinklist(ptr1,ptr2);
 cout<<"\5";
 temp = root;
 while(temp)
  {
 	cout<<temp->data<<" ";
 	temp = temp->right;
  }

 cout<<"\n";


 return 0;
}
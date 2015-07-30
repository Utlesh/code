#include <iostream>
using namespace std;
#include <stdio.h>
#include <stack>

struct node {
 int data;
 node *left;
 node *right;

}*root;

node *Makenode(node *root,int x)
{
	if(root == NULL)
	{
		root = new node;
		root->left = NULL;
		root->right = NULL;
		root->data = x;
		return root;
	}

	if(root->data>x)
		root->left = Makenode(root->left,x);
	if(root->data<x)
		root->right = Makenode(root->right,x);

	return root;
}

node *consTree()
{
	int a,b,num;
	cout<<"How many nodes in the tree:\n";
	cin>>num;

	for(int i=0;i<num;++i)
	{
      cin>>a;
      root = Makenode(root,a);
	}
}

void inorder(node *root)
{
	if(root)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

void pairSumToAValue(node *root,int sum)
{
 node *ptr1;
 node *ptr2;

 stack<node *>stk1,stk2;
 ptr1 = ptr2 = root;

 while(1)
 {
 	if(ptr1)
 	{
 		stk1.push(ptr1);
 		ptr1 = ptr1->left;
 	}

 	else if(ptr2)
 	{
 		stk2.push(ptr2);
 		ptr2 = ptr2->right;
 	}

 	else if(!stk1.empty() && !stk2.empty())
 	{
 		node *temp1 = stk1.top();
 		node *temp2 = stk2.top();
 
        if(temp1->data>temp2->data)
        		return;

        if((temp1->data + temp2->data) == sum)
            {
            	cout<<"Found sum: "<<" "<<temp1->data<<" "<<temp2->data<<"\n";
            	return;
            }

        if(temp1->data + temp2->data < sum)
          {
          	ptr1 = temp1->right;
            ptr2 = NULL;
            stk1.pop();
          }    

        else if(temp1->data + temp2->data > sum) 
          {
          	ptr2 = temp2->left;
          	ptr1 = NULL;
          	stk2.pop();
          }
 	}

 	else
 		return;
 }

}

void BSTtoDLL(node *root,node **head,node **tail)
{
	if(root == NULL)
		return;
	if(root->left)
		BSTtoDLL(root->left,head,tail);

	root->left = *tail;

	if(*tail)
		(*tail)->right = root; 
	else
		*head = root;
        
    *tail = root;

    if(root->right)
      BSTtoDLL(root->right,head,tail);  	
}

void pairSumToAValue2Method(node *root,int sum)
{
  node *head,*tail;
  tail = head = NULL;
  BSTtoDLL(root,&head,&tail);
 
  
  while(head!=tail)
  {
    if( head->data + tail->data == sum)
    {
    	cout<<"Sum Found: "<<head->data<<" "<<tail->data<<"\n";
    	break;
    }
    else if( head->data + tail->data < sum)
    {
    	cout<<head->data + tail->data<<"\n";
    	head = head->right;
    }
    else if( head->data + tail->data > sum)
    {
    	cout<<head->data+tail->data<<"\n";
    	tail = tail->left;
    }
  }

}

int main()
{
	consTree();
	inorder(root);
	cout<<"\n";
    int sum;
    cin>>sum;
    inorder(root);
    pairSumToAValue(root,sum);
    pairSumToAValue2Method(root,sum);
	return 0;
}
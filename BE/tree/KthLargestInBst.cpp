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

void KthLargestNum(int k,node *root)
{
	static int c = 0;

	if(root == NULL)
		return ;

	KthLargestNum(k,root->right);
  
	c++;

	if(k == c)
	{
		cout<<root->data<<"\n";
	}

	KthLargestNum(k,root->left);

}

int main()
{
	int k;
	consTree();
	cout<<"Enter the value of K for finding Kth largest number:\n";
	cin>>k;
	KthLargestNum(k,root);
	inorder(root);
	cout<<"\n";
	return 0;
}
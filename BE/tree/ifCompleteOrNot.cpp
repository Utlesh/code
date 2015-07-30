#include <iostream>
using namespace std;
#include <stdio.h>

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

int NumberOfNodesInTree(node *root)
{
	if(root == NULL)
		return 0;
	return 1 + NumberOfNodesInTree(root->left) + NumberOfNodesInTree(root->right);
}

bool ifComplete(node *root,int count,int index)
{
  if(root == NULL)
  	return 1;
  if(count<=index)
  	return 0;
  return ifComplete(root->left,count,2*index+1)&&ifComplete(root->right,count,2*index+2);
  
}

int main()
{
	int k ;
	consTree();
	inorder(root);
	cout<<"\n";
	int count = NumberOfNodesInTree(root);
    if(ifComplete(root,count,0))
    	cout<<"Complete Tree:\n";
    else
    	cout<<"Not A complete tree:\n";

	cout<<"\n";
	return 0;
}
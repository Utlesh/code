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

int LCA(node *root,int a,int b)
{
	if(root == NULL)
		return 0;
	if(root->data == a || root->data == b)
		return 1;

	int left = LCA(root->left,a,b);
	int right = LCA(root->right,a,b);

	if(left&&right)
		return root->data;

	return left?left:right;

}

int main()
{
	int a,b;
	consTree();
	cin>>a>>b;
	cout<<LCA(root,a,b)<<"\n";
	inorder(root);
	cout<<"\n";
	return 0;
}
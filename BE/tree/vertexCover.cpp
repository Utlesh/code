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

int vertexCover(node *root)
{
	if(root == NULL)
		return 0;
    if(root->left == NULL && root->right == NULL)
    	return 0;

	int IncRoot = 1 + vertexCover(root->left) + vertexCover(root->right);
    
    int Sum = 0;
    if(root->left)
      Sum += 1 + vertexCover(root->left->left) + vertexCover(root->left->right);
    if(root->right)
      Sum += 1 + vertexCover(root->right->left) + vertexCover(root->right->right);

    return min(Sum,IncRoot);

}

int main()
{
	int a,b;
	consTree();

	cout<<vertexCover(root);
	inorder(root);
	cout<<"\n";
	return 0;
}
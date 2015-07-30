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

int maxPathSumFromOneLeaveTOAnotherLeave(node *root,int &sum)
{
	if(root == NULL)
		return 0;

	int left = maxPathSumFromOneLeaveTOAnotherLeave(root->left,sum);
	int right = maxPathSumFromOneLeaveTOAnotherLeave(root->right,sum);

	int temp = left + right + root->data;

	if(temp>sum)
	{
		sum = temp;
	} 

	return max(left,right) + root->data;

}

int main()
{
	consTree();
	inorder(root);
	cout<<"\n";
	int sum = 0;
	maxPathSumFromOneLeaveTOAnotherLeave(root,sum);
	cout<<sum<<"\n";
	return 0;
}
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

node *removePathHavingSizeLessThenKFromRoot(node *root,int lvl,int k)
{
   if(root == NULL)
   	 return NULL;

   	root->left  = removePathHavingSizeLessThenKFromRoot(root->left,lvl+1,k);
   	root->right = removePathHavingSizeLessThenKFromRoot(root->right,lvl+1,k);

   	if(lvl<k&&!root->left&&!root->right)
   	{
   		delete(root);
   		return NULL;
   	}

    return root;

}

int main()
{
	int k ;
	consTree();
	inorder(root);
	cout<<"\n";
    cin>>k;
	root = removePathHavingSizeLessThenKFromRoot(root,1,k);
	inorder(root);
	cout<<"\n";
	return 0;
}
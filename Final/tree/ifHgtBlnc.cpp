#include<iostream>
using namespace std;

struct node{
	int data;
	node *right;
	node *left;
}*root;


node *Mknode(int x,node *root)
{
	if(root==NULL)
	{
		node *temp = new node;
		temp->left = temp->right = NULL;
		temp->data = x;
		return temp;
	}

	if(root->data>x)
		root->left = Mknode(x,root->left);
	else
		root->right = Mknode(x,root->right);

	return root;
}

node *Create()
{
	int a,num,x;
	cout<<"How many nodes r in tree:\n";
	cin>>num;
	for (int i=0;i<num;++i)
	{
		cin>>x;
		root = Mknode(x,root);
	}

	return root;
}

int abs(int a,int b)
{
	return a>b?a-b:b-a;
}

int height(node *root)
{
	if(root==NULL)
		return 0;
	return max(height(root->left),height(root->right)) + 1;
}

bool ifHgtBlncd(node *root)
{
	if(root==NULL)
		return true;

	int x = height(root->left);
	int y = height(root->right);

	if(abs(x,y)>1)
		return false;
	else if(ifHgtBlncd(root->left)&&ifHgtBlncd(root->right))
		return true;
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

int main()
{
 root = Create();
 inorder(root);
 cout<<"\n";
 if((ifHgtBlncd(root)))
 	cout<<"Tree is Height balanced:\n";
 else
 	cout<<"Tree is not height balanced:\n";
 return 0;
}
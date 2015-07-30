#include <iostream>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
}*root;

int getmid(int a,int b)
{
	return (a+b)/2;
}

node *getNode(int data)
{
	node *root = new node;
	root->left = NULL;
	root->right = NULL;
	root->data = data;
	return root;
}

node *makeTree(int start,int end,int arr[])
{
  if(start > end)
  	return NULL;

  int mid = getmid(start,end);
  node *root = getNode(arr[mid]);
  root->left = makeTree(start,mid-1,arr);
  root->right = makeTree(mid+1,end,arr);
  return root;
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
	int num,arr[100];
	cout<<"How many elements in array:\n";
	cin>>num;

	for(int i=0;i<num;++i)
		cin>>arr[i];
 
    root = makeTree(0,num-1,arr); 
    inorder(root);
    cout<<"\n";
    return 0;
}
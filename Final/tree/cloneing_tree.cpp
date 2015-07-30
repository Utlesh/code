#include<iostream>
using namespace std;

struct node{
 int data;
 node *right;
 node *left;
}*root,*p;

node *Mknode(node *root,int num)
{
 if(root==NULL)
  {
   node *temp = new node; 
   temp->right = NULL;
   temp->left = NULL;
   temp->data = num;
   return temp;
  }

 if(root->data>num)
  root->left = Mknode(root->left,num);
 if(root->data<num)
  root->right = Mknode(root->right,num);
 
 return root;
}

node *create()
{
 int i,num,x;
 cout<<"How many nodes u want:\n";
 cin>>num;

 for(i=0;i<num;++i)
  {
   cin>>x; 
   root = Mknode(root,x);
  }
 return root;
}

void inorder(node *root)
{
 if(root!=NULL)
  {
   inorder(root->left);
    cout<<root->data<<" ";
   inorder(root->right);
  }
}

node *clone(node *root,node *p)
{
 if(root==NULL)
  return NULL;
 if(root) 
  {
   p = new node;
   p->data = root->data;
   p->left = clone(root->left,p);
   p->right = clone(root->right,p);
   return p;
  }  
}

int main()
{
 root = create();
 inorder(root);
 node *p;
 p = clone(root,p);
 inorder(p);
 cout<<"\n";
 return 0;
}

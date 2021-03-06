#include<iostream>
using namespace std;

struct node{
 int data;
 node *right;
 node *left;
}*root;

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

void bst_dll(node *root,node **link)
{
 if(root==NULL)
  return ;

 static node *prev = NULL;
 bst_dll(root->left,link);
 if(prev==NULL) 
  *link = root;
 else
  {
   root->left = prev;
   prev->right = root;
  }

  prev = root;
  bst_dll(root->right,link);
}

void display(node *link)
{
 while(link)
  {
   cout<<link->data<<" ";
   link = link->right;
  }
}

int main()
{
 root = create();
 inorder(root);
 cout<<"\n";
 node *link;
 bst_dll(root,&link);
 display(link);
 return 0;
}

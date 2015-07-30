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

node *create(node *root)
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

bool compare(node *root,node *p)
{
  if(root==NULL&&p==NULL)
    return true;
  if(root==NULL||p==NULL)
   return false;
  return root->data==p->data&&compare(root->left,p->left)&&compare(root->right,p->right);
   
}

bool sub_tree(node *root,node *p)
{
 if(p==NULL)
  return true;
 if(root==NULL)
  return false;

 if(compare(root,p))
    return true;
  return sub_tree(root->left,p)||sub_tree(root->right,p);
 
}

int main()
{
 root = create(root);
 p = create(p);
 inorder(root);
 cout<<"\n";
 inorder(p);
 inorder(root);
 cout<<"\n";
 if(sub_tree(root,p))
  cout<<"Second tree is a sub tree of first one\n";
 else
  cout<<"Second tree is not a sub tree of first one\n";
 return 0;
}

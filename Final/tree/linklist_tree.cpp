#include<iostream>
using namespace std;
#include<vector>
vector<int>v;

struct node{
 int data;
 node *right;
 node *left;
};

struct linklist{
 int data;
 linklist *right;
};

linklist *create(linklist *link,int num)
{
 int x;
 for(int i=0;i<num;++i)
  {
   if(link==NULL)
    {
     link = new linklist;
     cin>>x;
     link->data = x;
     link->right = NULL;
    }
  else
   {
    cin>>x;
    linklist *p = link;
    while(p->right)
       p = p->right;
     linklist *q = new linklist;
     q->data = x;
     p->right = q;
   }
 }
 return link;
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

node *Newnode(int data)
{
 node *p = new node;
 p->data = data;
 p->left = NULL;
 p->right = NULL;
 return p;
}

node *Mktree(linklist **link,int num)
{
 if(num<=0) 
  return NULL;

 node *left = Mktree(link,num/2);
 node *root = Newnode((*link)->data);
 root->left = left;
 *link = (*link)->right;
 root->right = Mktree(link,num-num/2-1);
 return root; 
}

void display(linklist *link)
{
 while(link)
  {
   cout<<link->data<<" ";
   link = link->right;
  }
}

int main()
{
 int num;
 linklist *link = NULL;
 cout<<"How many nodes u want in linklist:\n";
 cin>>num;
 link = create(link,num);
 display(link);
 node *root = Mktree(&link,num);
 inorder(root);
 cout<<"\n";
 return 0;
}

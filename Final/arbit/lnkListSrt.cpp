#include<iostream>
using namespace std;

struct node{
 int data;
 node *right;
}*root;

node *gettail(node *root)
{
 while(root!=NULL&&root->right!=NULL)
   root = root->right;

 return root;
}

void Mklist()
{
 int num,x;
 cout<<"How many nodes u want:\n";
 cin>>num;
 for(int i=0;i<num;++i)
  {
   cin>>x;
   struct node *temp = new node;
   if(root==NULL)
    {
      temp->right = NULL;
      temp->data = x;
      root = temp;
    }
    else
     {
      temp->right = root;   
      temp->data = x; 
      root = temp;
     }
  }
}

node *partation(node *root,node *end,node **newHead,node **newEnd)
{
 node *tail = end,*pivot = end,*cur = root,*prev=NULL; 
 while(cur!=pivot)
  {
    if(cur->data<=pivot->data)
     {
       if(*newHead==NULL)     
         *newHead = cur;
       prev = cur;
       cur = cur->right;
     }
    else
     {
      if(prev)
       prev->right = cur->right;
      node *tmp = cur->right;
      cur->right = NULL;
      tail->right = cur;
      tail = cur; 
      cur = tmp;
     }
  }

 if(*newHead==NULL)
   *newHead = pivot;

  *newEnd = tail;
  return pivot;
}

node *SortUtil(node *root,node *end)
{
 if(!root||root==end)
  return root;

 node *newHead,*newEnd;
 newHead = newEnd = NULL;
 node *pivot = partation(root,end,&newHead,&newEnd);
 
 if(newHead!=pivot)
  {
   node *tmp = newHead;
   while(tmp->right!=pivot)
    tmp = tmp->right;
    tmp->right = NULL;

   newHead = SortUtil(newHead,tmp);
   tmp = gettail(newHead);
   tmp->right = pivot;
  }

  pivot->right = SortUtil(pivot->right,newEnd);
 return newHead;
}

void qsort(node **root)
{
 *root = SortUtil(*root,gettail(*root));
}

void display(node *root)
{
 while(root!=NULL)
  {
   cout<<root->data<<" ";
   root = root->right;
  }
  cout<<"\n";

}

int main()
{
 Mklist();
 qsort(&root);
 display(root);
 return 0;
}

#include<iostream>
using namespace std;
#include<ctype.h>
#include<stdio.h>

struct node{
 char data;
 node *left;
 node *right;
};

class Stack
{
 int top;
 struct node *data[30];
 public:
 Stack()
 { top = -1;}
 
 void push(node *root)
  {
     data[++top] = root;
  }

 int isempty()
  {
    if(top==-1)
     return 1;
    else
     return 0;
  }

 node *pop()
  {
   return data[top--];
  }
 struct node *InputExpr();
};

node *Stack::InputExpr()
{
 char ch;
 while((ch=getchar())!='\n')
  {
   if(isalnum(ch))
    {
      node *top = new node;
      top->data = ch;
      top->left = NULL;
      top->right = NULL;
      push(top);
    }
   else
    {
     node *t1 = pop();
     node *t2 = pop();
     node *top = new node;
     top->data = ch;
     top->right = t1;
     top->left = t2;
     push(top);
   }
  }
 
 node *top = pop();
 return top;
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

int main()
{
 Stack s;
 node *top = s.InputExpr();
 inorder(top);
 cout<<"\n";
 return 0;
}

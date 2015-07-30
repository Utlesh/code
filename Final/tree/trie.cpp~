#include<iostream>
using namespace std;
#include<string.h>
#include<iomanip>

struct node{
 int value;
 node *childs[26];
};

struct trie{
 int count;
 node *root;
};

node *init()
{
 int i=0;
 node *root = new node;
 root->value = 0;
 while(i<26)
  {
   root->childs[i] = NULL;
   ++i;
  }

 return root;
}

trie *trieUTIL(char arr[],trie *p)
{
  int len = strlen(arr);
  node *crawler = p->root;
  p->count++;
       for(int i=0;i<len;++i)
       {
         int ind = char(arr[i]-'a');
           if(!crawler->childs[ind])
            crawler->childs[ind] = init();
         crawler = crawler->childs[ind];
      }
     crawler->value = p->count;       
 return p;
}

bool search(char arr[],trie *root)
{
 int len = strlen(arr);
  node *crawler = root->root;
 
       for(int i=0;i<len;++i)
       {
         int ind = char(arr[i]-'a');
           if(!crawler->childs[ind])
             return 0;
         crawler = crawler->childs[ind];
      }
   return (0 != crawler && crawler->value);
}
 
void searchUTIL(node **l,char *q,int len,int incr)
{
 
  for(int i=0;i<26;++i)
  {
   if((*l)->childs[i])
    {
      char chr = i+'a'; 
     //cout<<chr;  
      (q[len+incr]) = chr;
      searchUTIL(&((*l)->childs[i]),q,len,incr+1); 
    }
 }
  if((*l)->value)
   {
    for(int j=0;j<incr+len;++j)
      cout<<q[j];
    cout<<"\n";
   }
 
}
void auto_search(char *arr,trie *root)
{
 int len = strlen(arr);
   node *crawler = root->root;
 
       for(int i=0;i<len;++i)
       {
         int ind = char(arr[i]-'a');
         crawler = crawler->childs[ind];
      }
 
 searchUTIL(&crawler,arr,len,0);
}

int main()
{
 char arr[][10] = {"animal","ant","answer","sharukh","ankit","and","shrawan","anish","shruti"};
 trie *p = new trie;
 p->root = init();
 p->count =0;
 for(int i=0;i<9;++i)
   p = trieUTIL(arr[i],p);

/* if(search("niraj",p))
  cout<<"Element found in trie:\n";
 else
  cout<<"Element not present in trie\n";
 //char *str = new char[20];
  //str = "an";*/
 char str[20];
 cin>>str;
 auto_search(str,p);
 return 0;
}

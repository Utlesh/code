#include<iostream>
using namespace std;
#include<vector>

struct node{
 int b;
 int c;
};

vector<node *>v[10];
bool visited[10];

void addEdges(int num)
{
 int a,b,c;
 
 for(int i=0;i<num;++i)
  {
   cin>>a>>b>>c;
   struct node *temp = new node;
   temp->b = b;
   temp->c = c;
   v[a].push_back(temp);
   temp = new node;
   temp->b = a;
   temp->c = c; 
   v[b].push_back(temp);
  }
}

bool ifConnected(int a,int b,int col)
{
  visited[a] = true;
  for(vector<node *>::iterator itr = v[a].begin();itr!=v[a].end();++itr )
   {
     if((*itr)->b==b&&(*itr)->c==col)
      return true;
     if(!visited[(*itr)->b]&&(*itr)->c==col&&ifConnected((*itr)->b,b,col))
      return true;
   }
 return false;
}

int main()
{
 int num,col;
 cout<<"How many edges r there:\n";
 cin>>num;
 addEdges(num);
/* for(int a=0;a<10;++a){
 for(vector<node *>::iterator itr = v[a].begin();itr!=v[a].end();++itr )
  {
   cout<<" "<<(*itr)->b<<" "<<(*itr)->c;
  }cout<<"\n";}
*/
 for(col=1;col<4;++col)
  {
    if(ifConnected(0,3,col))
     { 
      cout<<"Given vertices r connected by colour No. :\n";
      break;
     }
    else
    { 
    for(int i=0;i<10;++i) 
     visited[i] = false; 
    }
  }
  
 if(col==4)
  cout<<"Given vertices r not connected:\n";
 else
 cout<<col<<"\n";
 return 0;
}

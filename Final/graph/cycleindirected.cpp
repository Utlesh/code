#include<iostream>
using namespace std;
#include<vector>
#define N 10

vector<int>v[N];

void addEdges()
{
 int a,b,num;
 cout<<"How many edges u want:\n";
 cin>>num;
 for(int i=0;i<num;++i)
   {
      cin>>a>>b;
      v[a].push_back(b);
   }
}

bool detectCycle(int a,bool visited[],bool stack[])
{
 if(visited[a]==false)
  {
    visited[a] = true;
    stack[a] = true;
    for(vector<int>::iterator itr = v[a].begin();itr!=v[a].end();++itr)
     {
       if(!visited[*itr]&&detectCycle(*itr,visited,stack))
         return true;
       else if(stack[*itr]) 
         return true;
     }
  } 
   stack[a] = false;
   return false;
}

int main()
{
 addEdges();
 bool visited[10],stack[10];
 //memset(visited,0,);
 if(detectCycle(0,visited,stack))
   cout<<"There is a cycle in Graph:\n";
 else
  cout<<"Cycle is not present in Graph:\n";
               
 return 0;
}

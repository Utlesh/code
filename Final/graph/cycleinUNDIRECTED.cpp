#include<iostream>
using namespace std;
#include<vector>
vector<int>v[10];

void addEdges()
{
 int num,a,b;
 cout<<"How many edges u want to add:\n";
 cin>>num;
 
 for(int i=0;i<num;++i)
  {
    cin>>a>>b;
    v[a].push_back(b);
  }
}

bool detectCycle(int a,bool visited[],int parent)
{
 visited[a] = true;
 for(vector<int>::iterator itr = v[a].begin();itr!=v[a].end();++itr)
  {
   if(!visited[*itr]&&detectCycle(*itr,visited,a))
     return true;
   else if(*itr!=parent)
     return true;
  }
  return false;
}

int main()
{
 addEdges();
 bool visited[10];
 if(detectCycle(0,visited,-1))
   cout<<"Graph contain's a cycle\n";
 else
  cout<<"Graph doesn't contain any cycle:\n";
 return 0;
}

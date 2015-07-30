#include<iostream>
using namespace std;
#include<vector>
#include<queue>

int num;
vector<int>vtr[20];
int visited[20],Level[20],T[20],P[20],N,node,nr;

void addEdges()
{	
 int a,b;
 cout<<"How many nodes r there:\n";
 cin>>num;
 for(int i=0;i<num;++i)
 {
  cin>>a>>b;
  vtr[a].push_back(b);
 }

}

void getLevels(int a)
{
 int i=0;	
 queue<int>q;
 q.push(a);
 Level[a] = i;
 while(q.size())
  { 
   ++i;	
   a = q.front();
   q.pop();
   for(vector<int>::iterator itr = vtr[a].begin();itr!=vtr[a].end();++itr)
    {
      q.push(*itr);
      Level[*itr] = Level[a] + 1;
      T[*itr] = a;
    }
  }
}

void dfs(int node, int T[] , int P[], int Level[], int nr)  
{
      int k;
   
  //if node is situated in the first 
  //section then P[node] = 1
  //if node is situated at the beginning
  //of some section then P[node] = T[node]
  //if none of those two cases occurs, then 
  //P[node] = P[T[node]]
      if (Level[node] < nr)
          P[node] = 1;
      else
          if(!(Level[node] % nr))
              P[node] = T[node];
          else
              P[node] = P[T[node]];

     visited[node] = 1;
     for(int i=1;i<15;++i)
     	if(!visited[i])
         dfs(i, T,P, Level, nr);
}


int LCA(int T[], int P[], int Level[], int x, int y)
  {
  //as long as the node in the next section of 
  //x and y is not one common ancestor
  //we get the node situated on the smaller 
  //lever closer
      while (P[x] != P[y])
          if (Level[x] > Level[y])
             x = P[x];
          else
     	       y = P[y];
           
  //now they are in the same section, so we trivially compute the LCA
      while (x != y)
          if (Level[x] > Level[y])
             x = T[x];
          else
             y = T[y];
      return x;
  }

int main()
{
  addEdges();
  getLevels(1);
  int a,b;
  dfs(1,T,P,Level,1);
  cin>>a>>b;
  cout<<LCA(T,P,Level,a,b)<<"\n"; 
  return 0;
}
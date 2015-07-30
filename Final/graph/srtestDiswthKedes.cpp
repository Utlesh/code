#include<iostream>
using namespace std;
#define R 4
#define C 4

int countRoutesWithKEdges(int graph[][C],int fst,int lst,int K)
{
  if(K==1&&graph[fst][lst])
  	return 1;
  else if(!K)
  	return 0;
  
  int count = 0;
  for(int i=0;i<R;++i)
  	if(graph[fst][i])
  		count += countRoutesWithKEdges(graph,i,lst,K-1);
  	return count;
}

int main()
{
	int fst,lst,K;
  int graph[][C] = { {0, 1, 1, 1},
                        {0, 0, 0, 1},
                        {0, 0, 0, 1},
                        {0, 0, 0, 0}
                      };
     cin>>fst>>lst>>K;
     cout<<countRoutesWithKEdges(graph,fst,lst,K)<<"\n";

     return 0;                 	
}
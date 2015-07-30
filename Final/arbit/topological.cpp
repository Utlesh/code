#include<iostream>
using namespace std;
#define MAX 10

void topSort(int graph[][MAX],int num)
{
 int visited[num],inorder[num];
  for(int i=0;i<num;++i)
   {
    visited[i] = 0;
    inorder[i] = 0;
    for(int j=0;j<num;++j)
     if(graph[j][i])
      ++inorder[i];
   }
/* 
  for(int i=0;i<num;++i)
   {
     for(int j=0;j<num;++j)
      cout<<graph[i][j];
     cout<<"\n";
   }

 for(int i=0;i<num;++i)
  cout<<inorder[i];
  cout<<"\n";
*/
 for(int i=0;i<num;++i)
  {
   int j=0;
   while(j<num)
    {
      if(!inorder[j]&&!visited[j])
       {
         visited[j]=1;
         cout<<j<<" ";
          for(int k=0;k<num;++k) 
           {
             if(graph[j][k])
               --inorder[k];
           }
         break;
       }
       j++;
    }
   if(j==num)
    {cout<<"Graph has cycle\n";break;}
  }
 cout<<"\n";
}

int main()
{
 int graph[10][10],num; 
  cout<<"How many vertices are there in graph:\n";
  cin>>num;
  cout<<"Enter the value of adejency matrix value:\n";
 
 for(int i=0;i<num;++i)
  for(int j=0;j<num;++j)
   cin>>graph[i][j];

  topSort(graph,num);
  return 0;
}

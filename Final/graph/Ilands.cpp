#include<iostream>
using namespace std;
#include<string.h>
#include<stdio.h>
#define COL 5
#define ROW 5

bool isSafe(int row,int col,int graph[][COL],int visited[][COL])
{
 if(row>=0&&row<ROW&&col>=0&&col<COL&&graph[row][col]&&!visited[row][col])
    return true;
 else
    return false;

}

bool dfs(int row,int col,int visited[][COL],int graph[][COL])
{
 
 static int rowCon[] = {-1,-1,-1,0,0,1,1,1};
 static int colCon[] = {-1,0,1,-1,1,-1,0,1};

 visited[row][col] = true;
  
 for(int i=0;i<8;++i)
  for(int j=0;j<8;++j)
   if(isSafe(row+rowCon[j],col+colCon[j],graph,visited))
      dfs(row+rowCon[j],col+colCon[j],visited,graph);

}

int main()
{
 
 int k=0;
int graph[][COL]= {  {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1}
    };
 
 int visited[ROW][COL];
  memset(visited,0,sizeof(visited));
 for(int i=0;i<ROW;++i)
  for(int j=0;j<COL;j++)
   { 
     if(!visited[i][j]&&graph[i][j])
       {
         dfs(i,j,visited,graph);
         ++k;
       }
   }

 cout<<k<<"\n";
 return 0;
}

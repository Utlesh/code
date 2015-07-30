#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <omp.h>
using namespace std;


#define V 3

int minKey(int key[], bool mstSet[])
{
   
   int min = INT_MAX, min_index;

   for (int v = 0; v < V; v++)
     if (mstSet[v] == false && key[v] < min)
         min = key[v], min_index = v;

   return min_index;
}


int printMST(int parent[], int n, int graph[V][V])
{
   printf("Edge   Weight\n");
   for (int i = 1; i < V; i++)
      printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}


void primMST(int graph[V][V])
{
     int parent[V]; 
     int key[V];   
     bool mstSet[V];  

     #pragma omp parallel for num_threads(V)
     for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

     
     key[0] = 0;     
     parent[0] = -1; 

     #pragma omp parallel for num_threads(1)
     for (int count = 0; count < V-1; count++)
     {
        
        int u = minKey(key, mstSet);

        
        mstSet[u] = true;

        #pragma omp parallel for num_threads(V)
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
             parent[v]  = u, key[v] = graph[u][v];
     }

     
     printMST(parent, V, graph);
}



int main()
{
   
   int graph[V][V] ;
   for(int i=0;i<V;i++){
    for(int j=0;j<V;j++){
      graph[i][j]=0;
    }
   }

   int e;
   cin>>e;
   for(int i=0;i<e;i++)
   {
    int src,dest,wt;
    cin>>src>>dest>>wt;
    graph[src][dest]=wt;
    graph[dest][src]=wt;
   }

    
    primMST(graph);

    return 0;
}

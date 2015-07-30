#include <stdio.h>
#include<iostream>
using namespace std;
int set[1000000];

bool isSubsetSum(int n, int sum)
{
    bool subset[sum+1][n+1];
    for (int i = 0; i <= n; i++)
      subset[0][i] = true;
 
    for (int i = 1; i <= sum; i++)
      subset[i][0] = false;
 
     for (int i = 1; i <= sum; i++)
     {
       for (int j = 1; j <= n; j++)
       {
         subset[i][j] = subset[i][j-1];
         if (i >= set[j-1])
           subset[i][j] = subset[i][j] || subset[i - set[j-1]][j-1];
       }
     }
 
     return subset[sum][n];
}
 
int main()
{
   int n,sum;
   cin>>n;
   for(int i=0;i<n;++i)
    cin>>set[i];
    cin>>sum;

  if (isSubsetSum(n, sum) == true)
     printf("YES\n");
  else
     printf("No\n");
  return 0;
}

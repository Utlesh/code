#include<iostream>
using namespace std;
#define R 3
#define C 3

int mincost(int arr[][C])
{
  int sol[R][C];

  sol[0][0] = arr[0][0];

  for(int i=1;i<C;++i)
  	sol[0][i] = arr[0][i] + sol[0][i-1];

  for(int i=1;i<R;++i)
  	sol[i][0] = arr[i][0] + sol[i-1][0];

  for(int i=1;i<C;++i)
  	for(int j=1;j<R;++j)
  		sol[i][j] = min(sol[i-1][j],sol[i][j-1]) + arr[i][j];

  return sol[R-1][C-1];
}

int main()
{
  int arr[R][C] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
  cout<<mincost(arr)<<"\n";
  return 0;
}
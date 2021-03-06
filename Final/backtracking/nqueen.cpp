#include<iostream>
using namespace std;

#define N 4

bool issafe(int sol[N][N],int row,int col)
{
 int i,j;
 for(int k=0;k<col;++k)
  if(sol[row][k])
   return false;


    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (sol[i][j])
            return false;
    }
 
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
    {
        if (sol[i][j])
            return false;
    }
 
    return true;
}

bool nqueen(int sol[N][N],int ind)
{
 if(ind>=N)
   return true;
 else
   for(int i=0;i<N;++i)
    {
      if(issafe(sol,i,ind))
       {
         sol[i][ind] = 1;
         if(nqueen(sol,ind+1))
            return true;
         sol[i][ind] = 0;
       }
    }
  return false;
}

void display(int sol[N][N])
{
 for(int i=0;i<N;++i)
  {
    for(int j=0;j<N;++j)
     cout<<sol[i][j];
     cout<<"\n";
  }
}

int main()
{
 int sol[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
 if(nqueen(sol,0))
  cout<<"Solution is possible nd it is:\n";
  display(sol);
  return 0;
}

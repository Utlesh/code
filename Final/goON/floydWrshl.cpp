#include<iostream>
using namespace std;
#define R 5
#define C 5

int sol[R][C];
void flydWrshl(int arr[][C])
{

  for(int i=0;i<R;++i)
  	for(int j=0;j<C;++j)
      sol[i][j] = arr[i][j];

   for(int k=0;k<C;++k)
  	for(int i=0;i<R;++i)
  	 for(int j=0;j<C;++j)
  	  if(sol[i][j] || sol[i][k]&&sol[k][j])
  	   sol[i][j] = 1;

  			for(int i=0;i<R;++i)
  			{
  				cout<<"\n";
  				for(int j=0;j<C;++j)
  					cout<<sol[i][j]<<" ";
  			}

  			cout<<"\n";
}

int main()
{
	int arr[][C] = {
		 {0,1,0,0,0},
         {0,0,0,0,1},
         {0,0,0,1,0},
         {1,0,0,0,0},
         {0,0,0,0,0}
	};

	flydWrshl(arr);
	return 0;
}
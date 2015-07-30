#include<iostream>
using namespace std;

int sol[10][100];
int coinChng(int arr[],int size,int cash)
{
	int x=0,y=0;
	for(int i=0;i<size;++i)
    {
      for(int j=0;j<=cash;++j)
      {
      	if(j==0)
      		sol[i][j] = 1;
      	else if(!i&&j>=arr[i]&&sol[i][j-arr[i]])
      		sol[i][j] = 1;
      	else 
      		{
      			if(j>=arr[i])
      			 x = sol[i][j-arr[i]];
      			y = sol[i-1][j];
      			sol[i][j] = x+y;
      		}
      		cout<<sol[i][j]<<" ";
      		x=y=0;
      }
      cout<<"\n";
	}
   return sol[size-1][cash];
}


int main()
{
	int cash;
	int arr[] = {2,3,5,6};
	cin>>cash;
	cout<<coinChng(arr,sizeof(arr)/sizeof(arr[0]),cash)<<"\n";
    return 0;
}
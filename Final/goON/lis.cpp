#include<iostream>
using namespace std;

int lis(int arr[],int size)
{
	int max=0,*sol = new int[size];
	for(int i=0;i<size;++i)
		sol[i] = 1;

	for(int i=1;i<size;++i)
		for(int j=0;j<i;++j)
		{
			if(arr[i]>arr[j]&&sol[i]<sol[j]+1)
				sol[i] = sol[j] + 1;

			   if(sol[i]>max)
			   	max = sol[i];
		}
  return max;
}

int main()
{
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	cout<<lis(arr,sizeof(arr)/sizeof(arr[0]))<<"\n";
    return 0;
}
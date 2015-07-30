#include<iostream>
using namespace std;

int arr[20];

void upAdjst(int arr[])
{
 int x = arr[0];
 while(x&&x!=1)
 {
  if(arr[x/2]>arr[x])
    {
    	int tmp = arr[x];
    	arr[x] = arr[x/2];
    	arr[x/2] = tmp;
    }
    x = x/2;
 }
}

void sort(int arr[])
{
	int x = arr[0];
	while(arr[0])
	{
	  cout<<arr[1]<<" ";
	  arr[1] = arr[arr[0]];
	  arr[0]--;
	  upAdjst(arr);
	}
}

void addToHeap(int arr[],int num)
{
	arr[arr[0]+1] = num;
    arr[0]++;
    upAdjst(arr);
}

int main()
{
	int x,num;
	cout<<"How many nubers r there:\n";
	cin>>num;
	for(int i=0;i<num;++i)
	  {
	  	cin>>x;
	  	addToHeap(arr,x);
      }
   
    for(int i=1;i<=num;++i)
      cout<<arr[i]<<" ";
      cout<<"\n";

    sort(arr);
}
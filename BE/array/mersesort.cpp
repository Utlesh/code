#include <iostream>
using namespace std;

void merge(int arr[],int i,int j,int k)
{
	int l,m,result[200],itr=0;
	l = i;
	m = j+1;
    
	while(l<=j&&m<=k)
	{
		if(arr[l]<arr[m])
		{
		  result[itr] = arr[l];
		  ++l;	++itr;
		}

		else
		{
			result[itr] = arr[m];
			++m;++itr;
		}
	}

    
    while(l<=j)
    {
    	result[itr] = arr[l];
		  ++l;	++itr;
    }

    while(m<=k)
    {
    	result[itr] = arr[m];
		  ++m;	++itr;
    }

   
   for(l=i,j=0;i<=k;++i,++j)
      arr[i] = result[j];
}

int mergeSort(int arr[],int i,int j)
{
	int k;
	if(i<j)
	{
	  k = (i+j)/2;
	  mergeSort(arr,i,k);
	  mergeSort(arr,k+1,j);
	  merge(arr,i,k,j);
    }
}

int main()
{
	int arr[100],num;
	cout<<"How many elements r there:\n";
	cin>>num;

	for(int i=0;i<num;++i)
		cin>>arr[i];

	mergeSort(arr,0,num-1);
	for(int i=0;i<num;++i)
		cout<<arr[i]<<" ";
	cout<<"\n";
	return 0;
}
#include <stdio.h>
#include <iostream>
using namespace std;

int arr[100];
int tree[100];
int num;

void update(int pos,int val)
{
	while(pos<=num)
	{
		tree[pos] += val;
		pos += (pos&(-pos));
	}
}

int read(int index)
{
	int sum = 0;
	while(index>0)
	{
		sum += tree[index];
		index -= (index&(-index));
	}

	return sum;
}

int read(int a,int b)
{
	int sum = tree[b];
	int idx = b;
	while(idx>a)
	{
		idx -= (idx&(-idx));
		sum += tree[idx];
	}
	
    while(idx<a)
    {
    	cout<<sum<<" "<<a<<"\n";
    	sum -= tree[a];
    	a -= (a&(-a));
    }

    return sum;
}

int main()
{
	int index,a,b;
	cout<<"How many elements r there in array:\n";
	cin>>num;

	for(int i=1;i<=num;++i)
			cin>>arr[i];

	for(int i=1;i<=num;++i)
	{
	 	update(i,arr[i]);
	}	

	cout<<"Enter the index upto which u want sum:\n";
	cin>>index;

	cout<<read(index)<<"\n";

	cout<<"Range Sum:\n";
	cout<<"Enter the range of index:\n";
	cin>>a>>b;
	cout<<read(a-1,b)<<"\n";
	return 0;
}
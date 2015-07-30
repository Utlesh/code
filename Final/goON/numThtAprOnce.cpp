#include<iostream>
using namespace std;

int main()
{
	int arr[10],num,res;
	cout<<"How many number r there:\n";
	cin>>num;
	for(int i=0;i<num;++i)
		cin>>arr[i];

    res = arr[0];
	for(int i=1;i<num;++i)
		res ^= arr[i];

	cout<<res<<"\n";

	return 0;
}
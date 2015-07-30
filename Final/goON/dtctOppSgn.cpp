#include<iostream>
using namespace std;

int main()
{
	int a,b;
	cout<<"Enter two numbers:\n";
	cin>>a>>b;
	if((a^b)<0)
		cout<<"Opposite signature:\n";
	else
		cout<<"Same signature:\n";

	return 0;
}
#include<iostream>
using namespace std;

int main()
{
	int num1,num2,sum=0,carry=0;
	cout<<"Enter two numbers:\n";
	cin>>num1>>num2;

	while(num1)
	{
		sum += num1^num2 + carry;
		num1 = num1&num2;
		carry = num1<<1;
	}

	cout<<sum<<"\n";
	return 0;
}
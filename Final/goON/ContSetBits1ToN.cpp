#include<iostream>
using namespace std;

int main()
{
	int num;
	cout<<"Enter value of N:\n";
	cin>>num;
        int cnt = 0;
	for(int i=1;i<=num;++i)
	{
		int j = i;
		 while(j)
		 {
			j = j&(j-1);
		    ++cnt;
		 }
	}

	cout<<cnt<<"\n";
	return 0;
}

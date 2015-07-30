#include <iostream>
#include <cstdio>
#include <string.h>
#include <stdlib.h>
#include <omp.h>

using namespace std;

int main()
{
	while(1)
	{
		int n,arr[2],rem,pos=0;
		int ch;
		cout<<"Enter a two digit number\n";
		cin>>n;
		while(n>0)
		{
			rem=n%10;
			arr[pos++]=rem;
			n=n/10;
		}

		arr[0]=arr[0]^arr[1];
		arr[1]=arr[0]^arr[1];
		arr[0]=arr[0]^arr[1];

		string ans="";
		string s;
		#pragma omp parallel for num_threads(2)
		for(int i=0;i<2;i++)
		{
			int temp=arr[i]*arr[i];
			if(temp<10)
			{
				s=to_string(temp);
				s="0"+s;
			}
			else
			{
				s=to_string(temp);
			}
			ans+=s;
		}
		
		int val=atoi(ans.c_str());
		int temp=arr[0]*arr[1]*2;
		temp=temp*10;
		val+=temp;

		cout<<"Square of given number: "<<val<<endl;
		
		cout<<"Do you want to continue?(1)"<<endl;
		cin>>ch;
		if(ch!=1)
		{
			break;
		}



	}
}
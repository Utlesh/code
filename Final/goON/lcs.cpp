#include<iostream>
using namespace std;
#include<string.h>

int lcs(char str1[],char str2[],int len1,int len2)
{
	int sol[len1+1][len2+1];

	for(int i=0;i<=len1;++i)
	{
		for(int j=0;j<=len2;++j)
		{
			if(i==0||j==0)
				sol[i][j] = 0;
			else if(str1[i-1]==str2[j-1])
				sol[i][j] = sol[i-1][j-1] + 1;
			else 
				sol[i][j] = max(sol[i][j-1],sol[j][i-1]);
		}
	}

	return sol[len1][len2];
}

int main()
{
	char str1[20],str2[20];
	cin>>str1>>str2;
	cout<<lcs(str1,str2,strlen(str1),strlen(str2))<<"\n";
	return 0;
}
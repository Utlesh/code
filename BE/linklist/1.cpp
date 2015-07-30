#include <iostream>
using namespace std;

int sum ;

int mod(char a,char b)
{
	int x = (int)(a);
	int y = (int) b;

	return x>y?x-y:y-x;
}

int min(int a,int b)
{
	return a<b?a:b;
}

int main()
{
	int num;
	cin>>num;
	char str1[num];
	cin>>str1;
	char str2[num];
	cin>>str2;

    for(int i=0;i<num;++i)
    {
    	int x = mod(str1[i] , str2[i]);
        int s = str1[i]>str2[i]?(int)str1[i]:(int)str2[i];
        int t = str1[i]<str2[i]?(int)str1[i]:(int)str2[i];
        int y = 10 - s + t ;
        int z = min(x,y);

        //cout<<x<<" "<<y<<" "<<z<<" \n" ;
        sum += z;
    }

  cout<<sum<<"\n";

 return 0;
}
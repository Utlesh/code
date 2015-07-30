#include<iostream>
using namespace std;
#include<string.h>

int main()
{
 int flag = 1,n;
 cin>>n;
 string s[101],concat;
 s[1] = "3";
 s[2] = "4";
 
 for(int i=3;i<101;++i)
  {
   if(flag)
   {
    concat = s[(i-1)/2] + "3";
    s[i] = concat;
    ++i;
    concat = s[(i-1)/2] + "4";
    s[i] = concat;
    flag = 0;
   }
  else if(!flag)
   {
    concat = s[(i-1)/2] + "3";
    s[i] = concat;
    ++i;
    concat = s[(i-1)/2] + "4";
    s[i] = concat;
    flag = 1;
   }
  }
 cout<<s[n]<<"\n";
 return 0;
}

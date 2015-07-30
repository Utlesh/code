#include<iostream>
using namespace std;
#include<string.h>
#include<vector>

int Zalgo(string str1,string str2)
{
  string s = str1+'$'+str2;
  int n = s.length();
  vector<int>z(n,0);
  int goal = str1.length();
  int k,r=0,l=0,i,b;
  for(k = 1; k<n; ++k)
  {
    if(k>r)
    {
      for(i=k ; i<n && s[i]==s[i-k] ; ++i);
      	if(i>k)
      	{
          z[k] = i - k;
          l = k;
          r = i - 1;
      	}
    }
    else
    {
      int zt = k-l , b = r - k + 1;
      if( z[zt] > b )
      {
        for ( i = r+1 ; i<n && s[i]==s[i-k] ;++i);
        	z[k] = i - k;
            l = k;
            r = i - 1;
      }
    }
    if(z[k]==goal)
    	return 1;
  }
  return 0;
}

int main()
{
  string str1,str2;
  getline(cin,str1);
  getline(cin,str2);
  	if(Zalgo(str1,str2))
  	cout<<"Pattern found \n";
  else
  	cout<<"Pattern not fonund\n";
  return 0;
}
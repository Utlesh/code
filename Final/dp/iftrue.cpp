#include<iostream>
using namespace std;
int arr[1000000];

int main()
{
 int n,sum;
 cin>>n;
 for(int i=0;i<n;++i)
  cin>>arr[i];
  cin>>sum;
 for(int i=0;i<n;++i)
   for(int j=i;j<n-1;++j)
     if(arr[i]+arr[j+1]==sum)
      {
       cout<<"YES\n";
       return 0;
      }

  cout<<"NO\n";
  return 0;
}

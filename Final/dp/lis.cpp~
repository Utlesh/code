#include<iostream>
using namespace std;

void lis(int arr[],int n)
{
 int a[n];
 for(int i=0;i<n;++i)
  a[i] = 1;

 for(int i=1;i<n;++i)
  {
   for(int j=0;j<i;++j)
    if(arr[i]>arr[j] && a[i]<a[j]+1)
     a[i] = a[j]+1;
  }
 int max = -1;
 for(int i=0;i<n;++i)
  {
   cout<<a[i]<<" ";
   if(max<a[i])
    max=a[i];
    
  }
 cout<<max<<"\n";
}

int main()
{
 int arr[] = {111,22,113,8,13,12,4};
 lis(arr,7);
 return 0; 
}

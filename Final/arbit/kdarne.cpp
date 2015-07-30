#include<iostream>
using namespace std;
#include<limits.h>

int kdarne(int arr[],int num)
{
 int i=0,start,end;
 int sum ,max;
 sum=max=arr[0];
//cout<<arr[9];
while(i<num-1)
{
 if(sum<0)
  {
   ++i;
   sum = arr[i]; 
   start = i;
   end = i;
  }
 else
   sum += arr[++i];
   
  if(sum>max)
    {
     max = sum;
     end=i;
    }
    
}
  cout<<start<<" "<<end<<"\n";
  return max;
}

int main()
{
 int arr[] = {-1,3,4,-4,-9,-1,2,8};
 //sizeof(arr/arr[0]);
 cout<<kdarne(arr,8)<<"\n";
 return 0;
}

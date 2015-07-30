#include<iostream>
using namespace std;

int starting0Pos(int arr[],int start,int end)
{
 int mid = (start+end)/2;
 if(arr[mid]==0&&arr[mid-1]==1)
  return mid;
 else if(arr[mid]==0)
   end = mid-1;
  else
   start = mid+1;

 starting0Pos(arr,start,end);
}

int main()
{
 int arr[] = {1,1,1,1,1,1,1,0,0,0,0};
 cout<<starting0Pos(arr,0,10)<<"\n";
 return 0;
}



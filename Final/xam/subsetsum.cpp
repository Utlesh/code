#include<iostream>
using namespace std;
#include<algorithm>

void subSetUtil(int arr[],int start,int num,int ind,int target,int sum,int subset[])
{
 
 if(sum==target)
  {
   for(int i=0;i<ind;++i)
    cout<<subset[i]<<" ";
    cout<<"\n";
    return ;
  }

 for(int i=start;i<=num;++i)
  {
   subset[ind] = arr[i];
   if(sum+ar[i]<=target)
  subSetUtil(arr,i+1,num,ind+1,target,sum+arr[i],subset);
  }
}

void subSetSum(int arr[],int num,int target)
{
 int total;
 int *subset = new int[10];
 sort(arr,arr+5); 
 for(int i=0;i<=num;++i)
  total += arr[i];

 if(arr[0]<=target&&total>=target)
  subSetUtil(arr,0,num,0,target,0,subset);
}

int main()
{
 int arr[] = {2,5,12,4,9,6};
 subSetSum(arr,5,9);
 return 0;
}

#include<iostream>
using namespace std;

void merge(int arr[],int l,int mid,int e)
{
 int i,j,k;
 int n1,n2;
 n1 = mid-l+1;
 n2 = e-mid;
 int lft[n1],rgt[n2];
 
 for(i=0;i<n1;++i)
  lft[i] = arr[l+i];
 for(i=0;i<n2;++i)
  rgt[i] = arr[1+mid+i];

 i = 0;
 j = 0;
 k = l;

while(i<n1&&j<n2)
 {
  if(lft[i]<=rgt[j])
  {
   arr[k] = lft[i];
   ++i;
  }
  
  else
  {
   arr[k] = rgt[j];
   ++j;
  }
  ++k;
 }
 
 while(i<n1)
  {
   arr[k] = lft[i];
   ++i;
   ++k;
  }
 
 while(j<n2)
  {
   arr[k] = rgt[j];
   ++j;
   ++k;
  }
 
}

void mrgsort(int arr[],int s,int e)
{
 if(s<e)
  {
   int mid = s+(e-s)/2;
   mrgsort(arr,s,mid);
   mrgsort(arr,mid+1,e);
   merge(arr,s,mid,e);
  }
}

void mrgSort(int arr[],int e)
{
 for(int i=0;i<=e;++i)
  cout<<arr[i]<<" ";
  cout<<"\n";
}

int main()
{
 
 int arr[] = {23,4,24,5,1,8,3,7};
 mrgsort(arr,0,7);
 mrgSort(arr,7);
 return 0;
}

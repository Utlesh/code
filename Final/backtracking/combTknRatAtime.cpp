#include<iostream>
using namespace std;

void combination(int arr[],int ind,int k,int start,int end,int comb[])
{

 if(ind==k)
  {
   for(int i=0;i<k;++i)
    cout<<comb[i]<<" ";
    cout<<"\n";
    return ;
  }

 for(int i=start;i<=end&&end-i+1>=k-start;++i)
  {
   comb[ind] = arr[i];  
   combination(arr,ind+1,k,i+1,end,comb);
  } 
}

int main()
{
 int comb[10];
 int arr[] = {1,2,3,4,5};
 combination(arr,0,3,0,4,comb);
 return 0;
}

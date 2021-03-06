#include<iostream>
using namespace std;

void swap(int *a,int *b)
{
 int c = *a;
  *a = *b;
  *b = c;
}

int partation(int arr[],int s,int e)
{
 int pivot = arr[e];
 int i = s-1;
 for(int j=s;j<=e-1;++j)
  {
   if(arr[j]<=arr[e-1])
    {
     ++i;
     swap(&arr[i],&arr[j]);
    }
  }
 swap(&arr[i+1],&arr[e]);

 return i+1;
}

void qsort(int arr[],int s,int e)
{
 if(s<e)
 {
  int p = partation(arr,s,e);
  qsort(arr,s,p-1);
  qsort(arr,p+1,e);
 }
}

void SotedArr(int arr[],int range)
{
 for(int i=0;i<range;++i)
  cout<<arr[i]<<" ";
  cout<<"\n";
}

int main()
{  
  int arr[] = {10, 7, 8, 9, 1, 5};                                                                             
  qsort(arr,0,5);
  SotedArr(arr,5);
  return 0;
}

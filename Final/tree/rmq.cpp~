#include<iostream>
using namespace std;
#include<math.h>
#include<limits.h>

int update(int *st,int arr[],int ss,int se,int pos,int val,int ind)
{

  if((ss==se)&&(ss==pos))
   {
     st[ss] = val;
     arr[pos] = val;
     return val;
   }

  else if(ss==se)
   {
    st[ind] = arr[ss];
    return arr[ss]; 
   }

   if(pos<ss&&pos<se)
    return INT_MAX;
   if(pos>ss&&pos>se)
    return INT_MAX;

  int mid = (ss+se)/2;
  st[ind] = min(update(st,arr,ss,mid,pos,val,2*ind+1),update(st,arr,mid+1,se,pos,val,2*ind+2));
  return st[ind];
}

int segUTIL(int *st,int arr[],int ss,int se,int ind)
{
 if(ss==se) 
  {
   st[ind] = arr[ss];
   return arr[ss];
  }
  
    int mid = (ss+se)/2;
     st[ind] = min(segUTIL(st,arr,ss,mid,2*ind+1),segUTIL(st,arr,mid+1,se,2*ind+2));
     return st[ind];
}

int rmq(int *st,int arr[],int ss,int se,int qs,int qe,int ind)
{
 if(qs<=ss&&qe>=se)
   return st[ind];
  if(qe<ss || qs>se) 
  return INT_MAX;
  
  int mid = (ss+se)/2;
  return min(rmq(st,arr,ss,mid,qs,qe,2*ind+1),rmq(st,arr,mid+1,se,qs,qe,2*ind+2));
}

int *insert(int arr[],int x)
{
 int a = int(ceil(log2(x)));
 int size = 2*pow(2,a)-1;
 int *st = new int[size];//(int)malloc(size*sizeof(int));
 segUTIL(st,arr,0,6,0);
 cout<<"Minimum between these elemnt is"<<" "<<rmq(st,arr,0,6,0,5,0)<<" "<<"\n";
 update(st,arr,0,6,4,40,0);
 cout<<"Minimum between these elemnt is"<<" "<<rmq(st,arr,0,6,0,5,0)<<" "<<"\n";
 return st;
}

int main()
{
 int arr[] = {12,15,19,31,1,8,4};
 insert(arr,7);
 //cout<<rmq(st,arr,0,6,1,3,0)<<"\n";
 return 0;
}

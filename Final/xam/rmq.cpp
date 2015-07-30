#include<iostream>
using namespace std;
#include<math.h>
#include<limits.h>

void update(int *ST,int ss,int se,int pos,int val,int ind)
{
 if(ss==se&&ss==pos)
  {
   ST[ind] = val;
   return ;
  }
 else if(ss==se)
    return ;

  if(pos>ss&&pos>se)
   return ;
  if(pos<ss&&pos<se)
   return;
  
  int mid = (ss+se)/2;
  update(ST,ss,mid,pos,val,2*ind+1);
  update(ST,mid+1,se,pos,val,2*ind+2);
}

int searchSeg(int *ST,int ss,int se,int qs,int qe,int arr[],int ind)
{
  if(qs<=ss&&se<=qe)
   return ST[ind];   

  if(qs>se || ss>qe)
    return INT_MAX;
 
 int mid = (ss+se)/2; 
 return min(searchSeg(ST,ss,mid,qs,qe,arr,2*ind+1),searchSeg(ST,mid+1,se,qs,qe,arr,2*ind+2));
}

int rmqUtil(int *ST,int ss,int se,int arr[],int ind)
{
 if(ss==se)
 {
  ST[ind] = arr[ss];
  return arr[ss];
 }

 int mid = (ss+se)/2; 
 ST[ind] = min(rmqUtil(ST,ss,mid,arr,2*ind+1),rmqUtil(ST,mid+1,se,arr,2*ind+2));
 return ST[ind];
}

int *rmq(int arr[],int num)
{
 int h = (int)ceil(log2(num));
 int size = 2*pow(2,h)-1; 
 int *ST = new int[size];
 rmqUtil(ST,0,num-1,arr,0);
 return ST;
}

int main()
{
 int arr[] = {4,12,9,45,1,3,10,12};
 int *ST = rmq(arr,8);
 for(int i=0;i<15;++i)
  cout<<ST[i]<<" ";
 cout<<searchSeg(ST,0,7,1,3,arr,0)<<"\n"; 
 update(ST,0,7,4,20,0);
 cout<<searchSeg(ST,0,7,0,4,arr,0)<<"\n";
 return 0;
}

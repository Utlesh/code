#include <iostream>
using namespace std;
#include <math.h>
#include <stdio.h>
#include <malloc.h>
#include <limits.h>

int getmid(int a,int b)
{
  return (a+b)/2;
}

int min(int a,int b)
{
 return a<b?a:b;
}

int rmqUtil(int *st,int sgst,int sgend,int qs,int qe,int index)
{
  if(qs<=sgst&&qe>=sgend)
  	return st[index];
  if( (qs>sgst && qs>sgend) || (qe<sgst && qe<sgend) ) 
     return INT_MAX;

  int mid = getmid(sgst,sgend);
  return  min(rmqUtil(st,sgst,mid,qs,qe,2*index+1),rmqUtil(st,mid+1,sgend,qs,qe,2*index+2));
}

int initTree(int *st,int sgst,int sgend,int index,int arr[])
{
   if(sgst==sgend)
    {
    	st[index] = arr[sgst];
    	return arr[sgst];
    }

    int mid = getmid(sgst,sgend);
    st[index] = min(initTree(st,sgst,mid,2*index+1,arr),initTree(st,mid+1,sgend,2*index+2,arr));
    return st[index];
}


int *consTree(int num)
{
	int size = (ceil)(log2(num));
    cout<<size<<"\n";
    size = (2*pow(2,size)) - 1; 
    int *st = (int *)(malloc(sizeof(int)*size));
    cout<<size<<"\n";
    return st;
}

int main()
{
	int num,arr[20],qs,qe;
	cout<<"Enter the number of elements in the array:\n";
	cin>>num;
	for(int i=0;i<num;++i)
		cin>>arr[i];

	int *st = consTree(num);
	initTree(st,0,num-1,0,arr);
	/*
	for(int i=0;i<15;i++)
	{
		cout<<st[i]<<" ";
	}
	*/
    cout<<"Enter the query start and query end index:\n";
    cin>>qs>>qe;

	cout<<rmqUtil(st,0,num-1,qs,qe,0)<<"\n";
    return 0;
}
#include<iostream>
using namespace std;

#define N 10

int min(int a,int b,int c)
{
 int temp = a<b?a:b;
  return  c<temp?c:temp;
}

void maxSquareMat(int arr[][N],int row,int col)
{
 int max = 0;
 for(int i=1;i<row;++i)
   for(int j=1;j<col;++j)
    {
     if(*(*(arr+i)+j)!=0)
     *(*(arr+i)+j) = min(*(*(arr+i-1)+j-1),*(*(arr+i-1)+j),*(*(arr+i)+j-1)) + 1;   
      if(*(*(arr+i)+j)>max)
       {max = *(*(arr+i)+j); 
      cout<<max<<" "<<i<<" "<<j<<" ";}
    }
 
 cout<<max<<"\n";
}

int main()
{
 int arr[10][10],row,col;
 cout<<"How many rows nd columns r there:\n";
 cin>>row>>col;
 for(int i=0;i<row;++i)
  for(int j=0;j<col;++j)
   cin>>arr[i][j];

 maxSquareMat(arr,row,col); 
 return 0;

}

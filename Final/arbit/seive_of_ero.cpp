#include<iostream>
using namespace std;

int main()
{
 int num,flag=0;
 cout<<"Enter number upto which u want to print prime:\n";
 cin>>num;
 cout<<"\n2 ";
 for(int i=3;i<=num;++i)
  {
   for(int j=2;j<i;++j)  
    {
     if(i%j==0)
      { 
         flag=1;
         break;
      }
   }
    
    if(flag!=1)
        cout<<i<<" ";
    else
      flag = 0;
  }
 cout<<"\n";
 return 0;
}

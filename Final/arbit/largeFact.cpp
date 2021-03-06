#include<iostream>
using namespace std;

int calculate(int ,int ,int *);

void fact(int num)
{
 int fac[500];
 fac[0] = 1;
 int size = 1;

 for(int i=2;i<=num;++i)
    size = calculate(i,size,fac);

 for(int i=size-1;i>=0;--i)
  cout<<fac[i];
  cout<<"\n";
}

int calculate(int num,int size,int fac[])
{
 int carry = 0;
 for(int i=0;i<size;++i) 
  {
   int k = fac[i]*num + carry ;
   fac[i] = k%10;
   carry = k/10;
  }

  while(carry)
   {
    fac[size] = carry%10;
    carry = carry/10;
    ++size;
   }
 return size;
}

int main()
{
 int num;
 cin>>num;
 fact(num);
 return 0;
}

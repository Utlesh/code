#include<iostream>
using namespace std;
#include<math.h>
#include<stdio.h>
/*
void primeFac(int num)
{
 int k=0;
 int arr[10];
   for(int j=2;j<=num;++j)
    {
     if(num%j==0)
      {
       arr[k] = j;
       num = num/j;
       ++k;
       j=1;
      }
   }

 for(int i=0;i<k;++i)
  cout<<arr[i]<<" ";
  cout<<"\n";
}

void factor(int n) 
     { 
       int i; 
       for(i=2;i<=(int)sqrt(n);i++) 
       { 
         while(n % i == 0) 
         { 
           printf("%d ",i); 
           n /= i; 
         } 
       } 
       if (n > 1) printf("%d",n); 
       printf("\n"); 
     } 
*/
int p,q,n,cnt=0;

int div(int num)
{
//  cout<<"f\n";
int i,square_root = (int)sqrt(num) + 1;
// cout<<square_root<<"\n";
 for (i = 1; i < square_root; i++){ 
   if (num % i == 0)
      {
        int x = pow(i,n);
        if(num%x)
          ++cnt;
        x = pow(num/i,n);
          if(num%x)
          ++cnt;
      }
     //cout << i <<"\n"<< num/i << endl;
}
}

int main()
{
 int num;
 cout<<"Entre the number:\n";
 cin>>p>>q>>n;
 for(int i=p;i<=p+q;++i)
  div(p);
cout<<cnt<<"\n";
 return 0;
}

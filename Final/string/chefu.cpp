#include<stdio.h>

long long int F[400002];
long long int B[400002];

int main()
{
 long long int till_now,max;
 long long int t,N,D,sub,add,ind,finl,i;
 scanf(" %lld",&t);
 while(t--)
   {
    scanf(" %lld",&N);
    for(i=0;i<N;++i)    
      scanf(" %lld",&F[i]);

    for(i=0;i<N;++i)   
       scanf(" %lld",&B[i]);

     scanf(" %lld",&D);
 
    finl = 1;
   long long int min = 9223372036854775807;
   printf("%lld",min);
   for(i=0;i<N;++i)
    {
      
      ind = D - F[i];
      sub = F[i]-B[i];
      if(ind<=0||B[i]==0)
       break;
      add = F[i]+B[i];
      int j = 1;
      max = sub;
     
      while(ind>max)  
      {
       max = sub*j;
       ++j; 
      }
      --j;
      //printf("%lld\n",max);
      till_now = j*add + D-max;
      if(min>till_now)
      {
       finl = i+1; 
       min = till_now;
       //printf("%lld\n",min);
      }
     ///printf("%lld\n",till_now);
    }
   if(i!=N)
    printf("%lld\n",i+1);
   else 
   printf("%lld\n",finl);
  }

 return 0;
}

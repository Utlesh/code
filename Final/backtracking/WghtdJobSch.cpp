#include<iostream>
using namespace std;
#include<algorithm>

struct node{
 int t1,t2,profit;
};

bool comp(node n1,node n2)
{
   if(n1.t1<n2.t1)
     return n1.t1<n2.t1;
   else if(n1.t1==n2.t1) 
    return n1.t2<n2.t2;
   
  return false; 
}

/*int findMaxProfit(node temp[],int start,int end,int sum[],int ind,int t1,int max,int temp)
{
 if(start==end)
   {
    for(int i=0;i<ind;++i)
      temp += sum[i];
     
    if(temp>max)
     max = temp;
     cout<<max<<" " ;
     return max;
   }

 for(int i=start;i<end;++i)
  {
    if(temp[i].t1>=t1)
      {
       sum[ind] = temp[i].profit ; 
       t1 = temp[i].t2;
       findMaxProfit(temp,i+1,end,sum,ind+1,t1,max,0);
      }
     else
      findMaxProfit(temp,i+1,end,sum,ind,t1,max,0);
  } 

 return max;
}
*/
int main()
{
 int job,t1,t2,profit,sum[10];
 node temp[10];
 cout<<"How many jobs r there:\n";
 cin>>job;

 for(int i=0;i<job;++i)
  {
    cin>>t1>>t2>>profit;    
    temp[i].t1 = t1;
    temp[i].t2 = t2;
    temp[i].profit = profit;
  }

  sort(temp,temp+job,comp);
 // cout<<findMaxProfit(temp,0,job,sum,0,0,-1,0)<<" \n";

  for(int i=0;i<job;++i)
   cout<<temp[i].t1<<" "<<temp[i].t2<<" "<<temp[i].profit<<"\n";
 return 0;
}

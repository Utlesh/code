#include<map>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 200010
#define maxlg 50
#define N 200010
typedef long long int LL;   

string str; 
int rank[N], pos[N]; 
int cnt[N], next[N];
bool bh[N], b2h[N]; 
 
bool smaller_first_char(int a, int b){
    return str[a] < str[b];
}
void suffixSort(int n){
 
    for (int i=0; i<n; ++i){
	    pos[i] = i;
    }
    sort(pos, pos + n, smaller_first_char);
    
    for (int i=0; i<n; ++i){
    bh[i] = i == 0 || str[pos[i]] != str[pos[i-1]];
    b2h[i] = false;
    }
    for (int h = 1; h < n; h <<= 1){
    int buckets = 0;
    for (int i=0, j; i < n; i = j){
    j = i + 1;
    while (j < n && !bh[j]) j++;
    next[i] = j;
    buckets++;
    }
    if (buckets == n) break; 
    for (int i = 0; i < n; i = next[i]){
    cnt[i] = 0;
    for (int j = i; j < next[i]; ++j){
    rank[pos[j]] = i;
    }
    }
    cnt[rank[n - h]]++;
    b2h[rank[n - h]] = true;
    for (int i = 0; i < n; i = next[i])
     {
      for (int j = i; j < next[i]; ++j)
       {
        int s = pos[j] - h;
        if (s >= 0)
        {
          int head = rank[s];
          rank[s] = head + cnt[head]++;
          b2h[rank[s]] = true;
        }
       }

    for (int j = i; j < next[i]; ++j)
     {
       int s = pos[j] - h;
        if (s >= 0 && b2h[rank[s]])
          {
             for (int k = rank[s]+1; !bh[k] && b2h[k]; k++) 
              b2h[k] = false;
          }
     }
    }

    for (int i=0; i<n; ++i)
      {
       pos[rank[i]] = i;
       bh[i] |= b2h[i];
      }
    }

    for (int i=0; i<n; ++i)
     rank[pos[i]] = i;
  }

int lcp[N];

LL getHeight(int n)
  {
    for (int i=0; i<n; ++i)
      rank[pos[i]] = i;
    lcp[0] = 0;
    for (int i=0, h=0; i<n; ++i)
     {
      if (rank[i] > 0)
       {
        int j = pos[rank[i]-1];
        while (i + h < n && j + h < n && str[i+h] == str[j+h])
        h++;
        lcp[rank[i]] = h;
        if (h > 0) 
         h--;
       }
    }
    
    LL sum=0;
    for(int i=0; i<n; ++i)
    	sum=sum+lcp[i];
    return sum;
}
     
int main()
{
	int long long len1,len2;
	int t;
	scanf("%d",&t);
while(t--)
{
	scanf("%lld%lld",&len1,&len2);
    LL ans1,ans2,ans3;
    cin>>str;
    LL len=len1;
    memset(lcp,0,sizeof lcp);
    memset(rank,0,sizeof lcp);
    memset(pos,0,sizeof lcp);
    memset(cnt,0,sizeof lcp);
    memset(next,0,sizeof lcp);
    memset(bh,0,sizeof bh);
    memset(b2h,0,sizeof bh);
    suffixSort(len);
    
    ans1=(len*(len+1))/2 - getHeight(len);
    cout<<getHeight(len)<<"\n";
    string tmp=str;
    cin>>str;
    len=len2;
    memset(lcp,0,sizeof lcp);
    memset(rank,0,sizeof lcp);
    memset(pos,0,sizeof lcp);
    memset(cnt,0,sizeof lcp);
    memset(next,0,sizeof lcp);
    memset(bh,0,sizeof bh);
    memset(b2h,0,sizeof bh);
    suffixSort(len);
   
    ans2=(len*(len+1))/2 - getHeight(len);
   cout<<getHeight(len)<<"\n";
    memset(lcp,0,sizeof lcp);
    memset(rank,0,sizeof lcp);
    memset(pos,0,sizeof lcp);
    memset(cnt,0,sizeof lcp);
    memset(next,0,sizeof lcp);
    memset(bh,0,sizeof bh);
    memset(b2h,0,sizeof bh);
    ans3=-LL(tmp.length()+1)*LL(str.length()+1);
    str=tmp+"$"+str;
  
    len=str.length();
    suffixSort(len);
    
    ans3=ans3 + (len*(len+1))/2 - getHeight(len);
    cout<<getHeight(len)<<"\n";
    ans3=2*ans3-ans1-ans2;
    ans3 = (ans1+ans2-ans3)/2;
    printf("%lld\n",ans3);
}    
    return 0;
    } 

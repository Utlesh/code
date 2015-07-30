#include<iostream>
using namespace std;
#include<stdio.h>
#include<vector>
#include<set>
#include<algorithm>
set<int>s;
int visited[10000001];
int arr[1000];
int cnt = 0;

vector<int>v[10000001];

void addEdges(int a,int b)
{
	v[a].push_back(b);
	v[b].push_back(a);
}

void dfs(int a)
{
	visited[a] = 1;
	for(vector<int>::iterator itr = v[a].begin();itr!=v[a].end();++itr)
		{
			if(!visited[*itr]&&*itr)
			  {
			  	++cnt;
			  	dfs(*itr);
			  }
		}
}

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	int t,a,b,n,m,k,ans,y;
	scanf("%d",&t);
	while(t--)
	{
		cnt = ans = y =0;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=0;i<m;++i)
		{
			scanf("%d%d",&a,&b);
			addEdges(a,b);
			s.insert(a);
			s.insert(b);
		}
    
     for(set<int>::iterator itr = s.begin();itr!=s.end();++itr)
      {
      	//printf("%d\n",*itr);
       if(!visited[*itr])
       	  {
       	  	 dfs(*itr);
       	  	 arr[y++] = cnt + 1;
       	  	 cnt = 0; 
       	  	// cout<<cnt<<"\n";
       	  }
      }

          sort(arr,arr+n,cmp);
        
          for(int i=0;i<k;++i)
          	ans += arr[i];

       	  printf("%d\n",ans);
	}
}

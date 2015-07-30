
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string>
#include <cassert>
 
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
 
#define forup(i,a,b) for(int i=a; i<b; ++i)
#define fordn(i,a,b) for(int i=a; i>b; --i)
#define rep(i,a) for(int i=0; i<a; ++i)
 
#define dforup(i,a,b) for(i=a; i<b; ++i)
#define dfordn(i,a,b) for(i=a; i>b; --i)
#define drep(i,a) for(i=0; i<a; ++i)
 
#define slenn(s,n) for(n=0; s[n]!=13 and s[n]!=0; ++n);s[n]=0
 
#define gi(x) scanf("%d",&x)
#define gl(x) cin>>x
#define gd(x) scanf("%lf",&x)
#define gs(x) scanf("%s",x)
 
#define pis(x) printf("%d ",x)
#define pin(x) printf("%d\n",x)
#define pls(x) cout<<x<<" "
#define pln(x) cout<<x<<"\n"
#define pds(x) printf("%.12f ",x)
#define pdn(x) printf("%.12f\n",x)
#define pnl() printf("\n")
 
#define fs first
#define sc second
 
#define pb push_back
 
const int inv=1000000000;
const int minv=-inv;
 
const int max_n=50010;
const int max_q=50010;
const int max_logn=16;
const int chunk=225;
 
int T;
int n,q;
char s[max_n+5];
 
// Suffix Arrays Codechunk
 
int logn,pown; 
int p[max_logn+1][max_n];
 
struct Lel
{
	int pr;
	int se;
	int ix;
};
struct less_Lel : public binary_function<Lel,Lel,bool>
{
	bool operator () (const Lel &a, const Lel &b) { return ( (a.pr<b.pr) or ( (a.pr==b.pr) and (a.se<b.se) ) ); }
};
Lel L[max_n];
 
int findlcp(int x, int y, int k, int p2k)
{
	if(k==-1)
		return 0;
	if(x>=n or y>=n)
		return 0;
	 
	if(p[k][x]==p[k][y])
		return p2k+findlcp(x+p2k,y+p2k,k-1,p2k/2);
	else
		return findlcp(x,y,k-1,p2k/2);
}
 
int perm[max_n];
int iperm[max_n];
 
int findlcp(int x, int y)
{
	if(x==-1 or x==n or y==-1 or y==n)
		return 0;
	return findlcp(iperm[x],iperm[y],logn,pown);
}
 
void f()
{
	logn=0; pown=1;
	while(pown<n)
	{
		pown*=2;
		logn+=1;
	}
	
	for(int i=0; i<n; ++i)
	{
		L[i].pr=s[i]-'a';
		L[i].se=0;
		L[i].ix=i;
	}
	sort(L, L+n, less_Lel());
	
	int ct=0;
	p[0][L[0].ix]=0;
	for(int i=1; i<n; ++i)
	{
		if( not (L[i].pr==L[i-1].pr and L[i].se==L[i-1].se) )
			++ct;
		p[0][L[i].ix]=ct;
	}
	
	int powc=1;
	for(int k=1; k<=logn; ++k)
	{
		for(int i=0; i<n; ++i)
		{
			L[i].pr=p[k-1][i];
			if(i+powc<n)
				L[i].se=p[k-1][i+powc];
			else
				L[i].se=-1;
			L[i].ix=i;
		}
		sort(L, L+n, less_Lel());
		
		ct=0;
		p[k][L[0].ix]=0;
		for(int i=1; i<n; ++i)
		{
			if( not (L[i].pr==L[i-1].pr and L[i].se==L[i-1].se) )
				++ct;
			p[k][L[i].ix]=ct;
		}
		
		powc*=2;
	}
}
 
// End of Codechunk
 
struct query
{
	int ql,qr,ix;
	query(){}
	query(int ql_, int qr_, int ix_) { ql=ql_; qr=qr_; ix=ix_; }
};
struct less_query : public binary_function <query,query,bool>
{
	bool operator() (const query &a, const query &b) { return (pii(a.qr,a.ql)<pii(b.qr,b.ql)); }
};
vector<query> Q[chunk+5];
 
int l,r,sub;
set<int> S;
set<int>::iterator it;
 
int tot[max_n];
int ptot[max_n+1];
int res[max_q];
 
int change(int x)
{
	//cerr<<"change @ "<<x<<"\n";
	it=S.upper_bound(x); int nxt=(*it);
	--it; int prv=(*it);
 
	int ret=0;
	ret+=findlcp(prv,x);
	ret+=findlcp(x,nxt);
	ret-=findlcp(prv,nxt);
	return ret;
}
 
void add(int x)
{
	//cerr<<"add @ "<<x<<"\n";
	sub+=change(perm[x]);
	S.insert(perm[x]);
}
void del(int x)
{
	//err<<"del @ "<<x<<"\n";
	S.erase(S.find(perm[x]));
	sub-=change(perm[x]);	
}
 
void incl()
{
	if(l<=r) del(l);
	++l;
}
void decl()
{
	--l;
	if(l<=r) add(l);
}
void incr()
{
	++r;
	if(l<=r) add(r);
}
void decr()
{
	if(l<=r) del(r);
	--r;
}
 
int main()
{
	gi(T);
 
	rep(z,T)
	{
		gs(s); slenn(s,n);
 
		f();
 
		//cout<<logn<<" "<<pown<<
                "\n";
		rep(i,n)
			cout<<i<<": "<<p[logn][i]<<"\n";
 
		rep(i,n)
		{
			perm[i]=p[logn][i];
			iperm[perm[i]]=i;
		}
 
		//cerr<<"Here 1\n";
 
		gi(q);
		for(int i=0; i<=(n-1)/chunk; ++i)
			Q[i].resize(0);
		rep(i,q)
		{
			int cl,cr;
			gi(cl); gi(cr);
			--cl; --cr;
 
			Q[cl/chunk].pb(query(cl,cr,i));
		}
		for(int i=0; i<=(n-1)/chunk; ++i)
			sort(Q[i].begin(),Q[i].end(),less_query());
 
		//cerr<<"Here 2\n";
                 for(int h=0;h<n;++h)
                   cout<<Q[]
		ptot[0]=0;
		rep(i,n)
		{
			tot[i]=n-i;
			ptot[i+1]=ptot[i]+tot[i];
		}
 
		//cerr<<"Here 3\n";
 
		//l=0; r=0; sub=0;
		//S.clear(); S.insert(-1); S.insert(n); S.insert(perm[0]);
		for(int i=0; i<=(n-1)/chunk; ++i)
		{
			if(Q[i].size()==0) continue;
 
			l=Q[i][0].ql; r=Q[i][0].ql; sub=0;
			S.clear(); S.insert(-1); S.insert(n); S.insert(perm[l]);
			rep(j,Q[i].size())
			{
				query cq=Q[i][j];
 
				while(l<cq.ql) incl();
				while(l>cq.ql) decl();
 
				while(r<cq.qr) incr();
				//while(r>cq.qr) decr();
 
				int cres=(ptot[r+1]-ptot[l]-sub);
				res[cq.ix]=cres;
			}
		}
 
		//cerr<<"Here 4\n";
 
		rep(i,q)
			pin(res[i]);
	}
 
	return 0;
}  

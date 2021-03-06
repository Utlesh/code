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
#include <cstring>
#include <climits>
#include <cctype>
#include <cassert>
#include <complex>
 
using namespace std;
 
#define ull unsigned long long
#define ill long long int
#define pii pair<int,int>
#define pb(x) push_back(x)
#define F(i,a,n) for(int i=(a);i<(n);++i)
#define FF(i,a,n) for(i=(a);i<(n);++i)
#define FD(i,a,n) for(int i=(a);i>=(n);--i)
#define FE(it,x) for(it=x.begin();it!=x.end();++it)
#define V(x) vector<x>
#define S(x) scanf("%d",&x)
#define Sl(x) scanf("%llu",&x)
#define M(x,i) memset(x,i,sizeof(x))
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
#define MAX(a,b) ((a)>(b)?(a):(b))
ill ABS(ill a) { if ( a < 0 ) return (-a); return a; }
#define fr first
#define se second
 
/* Relevant code begins here */
 
/* Input from file or online */
 
void input() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
}
 
/* Input opener ends */
 
#define REP(i,a,b) for(typeof(a) i=(a);i<(b);i++)
#define ll long long int
#define ii pair<int,int>
#define CLEAR(x,val) memset(x,val,sizeof(x))
#define SZ(v) (v).size()
#define N 200005
 
char str[N];                        //  input
int rr[N], pos[N];                //  output
int cnt[N], nn[N];                //internal
bool bh[N], b2h[N];
 
// Compares two suffixes according to their first characters
bool smaller_first_char (int a, int b){
  return str[a] < str[b];
}
 
void suffixSort(int n)
{
  //sort suffixes according to their first characters
    for (int i=0; i<n; ++i){
        pos[i] = i;
    }
    sort(pos, pos + n, smaller_first_char);
    //{pos contains the list of suffixes sorted by their first character}
 
    for (int i=0; i<n; ++i){
        bh[i] = i == 0 || str[pos[i]] != str[pos[i-1]];
        b2h[i] = false;
    }
 
    for (int h = 1; h < n; h <<= 1){
        //{bh[i] == false if the first h characters of pos[i-1] == the first h characters of pos[i]}
        int buckets = 0;
        for (int i = 0, j; i < n; i = j){
            j = i + 1;
            while (j < n && !bh[j]) j++;
                nn[i] = j;
                buckets++;
            }
            if (buckets == n) break; // We are done! Lucky bastards!
            //{suffixes are separted in buckets containing strings starting with the same h characters}
 
            for (int i = 0; i < n; i = nn[i]){
                cnt[i] = 0;
                for (int j = i; j < nn[i]; ++j){
                    rr[pos[j]] = i;
                }
            }
 
            cnt[rr[n - h]]++;
            b2h[rr[n - h]] = true;
            for (int i = 0; i < n; i = nn[i]){
                for (int j = i; j < nn[i]; ++j){
                    int s = pos[j] - h;
                    if (s >= 0){
                        int head = rr[s];
                        rr[s] = head + cnt[head]++;
                        b2h[rr[s]] = true;
                    }
                }
                for (int j = i; j < nn[i]; ++j){
                    int s = pos[j] - h;
                    if (s >= 0 && b2h[rr[s]]){
                        for (int k = rr[s]+1; !bh[k] && b2h[k]; k++) b2h[k] = false;
                    }
                }
            }
            for (int i=0; i<n; ++i){
                pos[rr[i]] = i;
                bh[i] |= b2h[i];
            }
    }
 
    for (int i=0; i<n; ++i){
        rr[pos[i]] = i;
    }
}
// End of suffix array algorithm
 
 
// Begin of the O(n) longest common prefix algorithm
// Refer to "Linear-Time Longest-Common-Prefix Computation in Suffix
// Arrays and Its Applications" by Toru Kasai, Gunho Lee, Hiroki
// Arimura, Setsuo Arikawa, and Kunsoo Park.
 
int height[N];
 
// height[i] = length of the longest common prefix of suffix pos[i] and suffix pos[i-1]
// height[0] = 0
 
void getHeight(int n)
{
    for (int i=0; i<n; ++i) rr[pos[i]] = i;
    height[0] = 0;
 
    for (int i=0, h=0; i<n; ++i){
        if (rr[i] > 0){
            int j = pos[rr[i]-1];
            while (i + h < n && j + h < n && str[i+h] == str[j+h]) h++;
            height[rr[i]] = h;
            if (h > 0) h--;
        }
    }
}
// End of lcp part
 
#define N 200005
 
ill D[N], SL[N], SR[N];
int LCP[N];
vector<int> len[N];
 
int main() {
    //input();
 
    int t; S(t);
    while ( t-- ) {
        scanf("%s",str);
        int n = strlen(str);
 
        suffixSort(n);
        getHeight(n);
    
        F(i,0,n) LCP[i] = height[i]; 
       LCP[0] = LCP[n] = -1;     
        for(int g=0;g<n+1;++g)
           cout<<LCP[g]<<" ";
            cout<<"\n";

        stack<pii> st;
        st.push(pii(LCP[0],0));
        F(i,1,n) {
            int now = LCP[i];
            while ( true ) {
                pii tp = st.top();
                if ( tp.fr < now ) break;
                st.pop();
            }
            pii tp = st.top();
            SL[i] = tp.se + 1;
            st.push(pii(now,i));
        }
 
        while ( !st.empty() ) st.pop();
        st.push(pii(LCP[n],n));
        FD(i,n-1,1) {
            int now = LCP[i];
            while ( true ) {
                pii tp = st.top();
                if ( tp.fr < now ) break;
                st.pop();
            }
            pii tp = st.top();
            SR[i] = tp.se - 1;
            st.push(pii(now,i));
        }
 
        // F(i,1,n) cout << SL[i] << " "; cout << endl;
        // F(i,1,n) cout << SR[i] << " "; cout << endl;
 
        F(i,0,n+5) D[i] = 0;
        F(i,0,n+5) len[i].clear();
 
        F(i,1,n) {
            int now = LCP[i];
            len[now].pb(i);
        }
 
        FD(i,n,1) {
            F(j,0,len[i].size()) {
                int whr = len[i][j];
                if ( j == 0 || whr > SR[len[i][j-1]] ) {
                    ill range = SR[whr] - SL[whr] + 2;
                    int height = LCP[whr];
                    height = min(height,LCP[whr]-LCP[SL[whr]-1]);
                    height = min(height,LCP[whr]-LCP[SR[whr]+1]);
                    D[range] += range*height;
                }
            }
        }

        int usum = 0;
        for(int u=2;u<n+1;++u)
            usum += D[u];
          cout<<usum<<"\n";
          
        D[1] = n;
        D[1] *= (n+1);
        D[1] /= 2;
 
        FD(i,n,2) D[i] += D[i+1];
        for(int u=0;u<n;++u)
            cout<<D[u]<<" ";
             cout<<"\n";
        int q; S(q);
        F(i,0,q) {
            int x; S(x);
            printf("%lld\n", D[x]);
        }
 
    }
 
    
 
    return 0;
} 
#include<iostream>
using namespace std;
#include<set>
#include<vector>

int visited[100];
set<int>st;
std::vector<int> v[100];

void addEdges()
{
	int a,b,num;
	cout<<"How many edges r there:\n";
	cin>>num;
	for(int i=0;i<num;++i)
      {
      	cin>>a>>b;
      	st.insert(a);
      	st.insert(b);
      	v[a].push_back(b);
      	v[b].push_back(a);
      }
}

void articulation_point(int a)
{
	visited[a] = 1;
	for(vector<int>::iterator itr = v[a].begin();itr!=v[a].end();++itr)
	{
		if(!visited[*itr])
			articulation_point(*itr);
	}
}

int dfs(int a)
{
	visited[a] = 1;
	int cnt = 0;
	for(set<int>::iterator itr = st.begin();itr!=st.end();++itr)
		if(!visited[*itr])
			{
				//cout<<*itr<<"\n";
				++cnt;
				if(cnt==2)
					break;
				articulation_point(*itr);
            }
      return cnt;      
}


int main()
{
	addEdges();
	for(set<int>::iterator itr = st.begin();itr!=st.end();++itr)
           {
           	 if(dfs(*itr)>1)
      	    	cout<<*itr<<" ";
      		for(int i=0;i<20;++i)
      			visited[i] = 0;
          }

    return 0;
}
#include<iostream>
using namespace std;
#define R 5
#define C 5
#define INF 99999

int cost[R][C];

void allPairSortestPath(int arr[][C])
{
	for(int i=0;i<R;++i)
		for(int j=0;j<C;++j)
			if(arr[i][j])
			cost[i][j] = arr[i][j];
		    else 
		    	cost[i][j] = INF;

		for(int k=0;k<C;++k)
			for(int i=0;i<R;++i)
				for(int j=0;j<C;++j)
					if(cost[i][j]>cost[i][k]+cost[k][j])
						cost[i][j] = cost[i][k] + cost[k][j];

					for(int i=0;i<R;++i)
					 {
						for(int j=0;j<C;++j)
							cout<<cost[i][j]<<" ";
						cout<<"\n";
					 }

}

int main()
{
	int arr[][C] = {
		 {0,5,0,0,0},
         {0,0,6,0,6},
         {0,0,0,2,0},
         {2,0,0,0,0},
         {0,0,0,1,0}
     };

     allPairSortestPath(arr);

     return 0;
}
#include <iostream>
using namespace std;
#define COL 500
#define ROW 500

bool visited[500][500];
char arr[500][500];

int x,y,s,t;

int isSafe(char arr[][COL], int row, int col, bool visited[][COL])
{
    return (row >= 0) && (row < ROW) &&     
           (col >= 0) && (col < COL) &&    
           (arr[row][col] == '.' && !visited[row][col]); 
}

int dfs(char arr[][COL],int x,int y,int s,int t,bool visited[][COL])
{
  	static int rowNbr[] = {-1, -1, -1,  0, 0,  1, 1, 1};
    static int colNbr[] = {-1,  0,  1, -1, 1, -1, 0, 1};
 
    if(x==s&&y==t)
    	return 1;

    visited[x][y] = true;
    for (int k = 0; k < 8; ++k)
        if (isSafe(arr, x + rowNbr[k], y + colNbr[k], visited) )
            {
            	cout<<x + rowNbr[k]<<" "<<y+colNbr[k]<<"\n";
            	if(dfs(arr, x + rowNbr[k], y + colNbr[k],s,t ,visited))
            		return 1;
            	
            }
        
            return 0;
}

int main()
{
  int a,b;
  cin>>a>>b;
  for(int i=0;i<a;++i)
  	for(int j=0;j<b;++j)
  		cin>>arr[i][j];

  	cin>>x>>y;
  	cin>>s>>t;
  
    if(dfs(arr,x-1,y-1,s-1,t-1,visited))
      cout<<"1";
    else
      cout<<"-1"; 

    return 0;
}
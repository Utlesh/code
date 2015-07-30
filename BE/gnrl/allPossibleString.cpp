#include <iostream>
using namespace std;
#include <string>
#define R 3
#define C 3

void recur(string s[][C],int a,int b)
{
 static  string output[3];
 output[a] = s[a][b];

 if(a == R-1)
 {
 	for(int i=0;i<C;++i)
 		cout<<output[i]<<"  ";
 	cout<<"\n";
 	return ;
 }

 for(int i=0;i<C;++i)
 	recur(s,a+1,i);
}

int main()
{
  string s[3][3] = {{"we","I","you"},
   {"are","have","willl"},
   {"dogs","win","nothing"}
  };

  

  for(int i=0;i<C;++i)
   	 recur(s,0,i);

  return 0;
}
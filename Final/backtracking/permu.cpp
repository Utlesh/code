#include<iostream>
using namespace std;
#include<string.h>

void swap(char *a,char *b)
{
 char c = *a;
 *a = *b;
 *b = c;
}

void permu(char *str,int strt,int end)
{
 if(strt==end)
  cout<<str<<"\n";
 else 
  for(int i=strt;i<=end;++i)
   {
     if(i==strt || *(str+strt)!=*(str+i))
     {
     swap(str+strt,str+i);
     permu(str,strt+1,end);
     if(i==strt || *(str+strt)!=*(str+i))
     swap(str+strt,str+i);
   }}
}

int main()
{
 char str[10];
 cout<<"Enter the string:\n";
 cin>>str;
 permu(str,0,strlen(str)-1);
 return 0;
}

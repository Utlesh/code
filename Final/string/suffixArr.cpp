#include<iostream>
using namespace std;
#include<algorithm>
#include<string.h>

int cmp(char *s1,char *s2)
{
 return strcmp(s1,s2) < 0;
}

void suffixArr(char *str,int num)
{
  char *str1[num] ;//= new char;
  for(int i=0;i<num;++i)
    str1[i] = str+i; 
 
  sort(str1,str1+num,cmp);
  
  for(int i=0;i<num;++i)
    cout<<*(str1+i)<<"\n";
}

int main()
{
 char str[10];
 cin>>str;
 suffixArr(str,strlen(str));
 return 0;
}

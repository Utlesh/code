#include <cstdio>
#include<iostream>
using namespace std;

string ip()
{
    string i="";
    int temp=getchar_unlocked();
    while(temp<'a'||temp>'z')
        temp=getchar_unlocked();
    while(temp>='a'&&temp<='z')
    {
        i += (char)temp;
        temp=getchar_unlocked();
    }
    return i;
}

int main()
{
    std::cout<<ip()<<"\n";
	return 0;
}
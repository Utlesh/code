#include<iostream>
using namespace std;
#include<stdio.h>

int main()
{
	char ch;
	int count = 0;
    FILE *fp = fopen("/home/utlesh/arbit/1.cpp","r");
    while((ch=fgetc(fp))!=EOF)
    {
    	if(ch=='\n')
    		++count;
    }

    printf("Number of lines in the file is : %d\n",count);
    return 0;
}
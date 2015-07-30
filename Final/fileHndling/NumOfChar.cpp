#include<iostream>
using namespace std;
#include<stdio.h>

int main()
{
	int count = 0;
	char ch;
	FILE *fp1 = fopen("/home/utlesh/arbit/1.cpp","r");
    FILE *fp2 = fopen("/home/utlesh/arbit/2.cpp","w");
	if(fp1==NULL)
		 printf("File could not be opend\n");
	else    
	while((ch = fgetc(fp1))!=EOF)
	{
	  ++count;
	  fputc(ch,fp2);
	 // printf("%c",ch);
	}

	printf("Number of characters read from the file is : %d\n",count);
	return 0;
}
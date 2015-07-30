#include<iostream>
using namespace std;
#include<stdio.h>

int main()
{
	int x = 1;//x = 0x123456 %.2x *t
	int *a = &x;
	char *t = (char *)a;
	if(*t)
	printf("Little Endian:\n");
    else
    printf("Big Endian:\n");
	return 0;
}
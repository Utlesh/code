#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>

int main()
{
  size_t len = 0;
  ssize_t read;
  FILE *fp = fopen("/home/utlesh/arbit/1.cpp","r");
  FILE *fpw = fopen("/home/utlesh/arbit/10.cpp","w");
  if(fp==NULL)
  {
  	cout<<"File could not be opened:\n";
  	exit(EXIT_FAILURE);
  }

  char *Line = NULL;
  while((read = getline(&Line,&len,fp))!=-1)
  {
  	//printf("%s",Line);;
    fputc(Line,fpw);  
  }

 fclose(fp);
       if (Line)
           free(Line);
       exit(EXIT_SUCCESS);

}
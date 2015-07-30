#include "VMFT.h"
#include <cstdlib>
#include <string.h>
#include <cstdio>
using namespace std;

VMFT :: VMFT(void)
{
	ptrToFirstFileNode = NULL;		// Pointer to first file node of VMFT is initialised to NULL
	numberOfFiles  = 0;				// Initially Number of files = 0
}

VMFT :: ~VMFT(void){}


// Function to search the File having FileName same as argument(fileName) 
FileNode* VMFT::searchFile(char *fileName)
{
	// Pointer to traverse the list of File Nodes of VMFT
	FileNode *fptr = ptrToFirstFileNode;

	// Iterative traversing of the all the File Nodes
	while(fptr)
	{
		// Comparing the Filename of File Node with the argument(FileName)
		// if found returns Pointer to the current File Node;
		if(strcmp(fptr->fileName, fileName) == 0)
			return fptr;
				
		fptr = fptr->nextFileNode;
	}

	// if File is not found then it returns NULL
	return NULL;
}

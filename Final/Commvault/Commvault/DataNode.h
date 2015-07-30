#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cstdio>

using namespace std;

class DataNode
{
public :

	unsigned int uiStartLoc;					// Starting location of Data Block
	unsigned int uiEndLoc;						// Ending location of Data Block	
	DataNode * nextDataNode;					// Pointer to NEXT Data Block

	DataNode(void);								// Constructor to initialise all members of Data Block
	~DataNode(void);

	// Function to PRINT information of a Data Block
	void printDataNode(void * buffer)
	{
		char data[100];
		printf("\n\n\n=======================================");
		readDataNode(data, buffer);
		*(data + uiEndLoc - uiStartLoc + 1) = '\0';
		printf("\n\n\tContents       : %s",data);
		printf("\n\n\tStart Location : %d", uiStartLoc);
		printf("\n\n\tEnd Location   : %d", uiEndLoc);
		printf("\n\n=======================================");

		// recursive call to the linked list of data blocks till the NULL
		if(nextDataNode)
			nextDataNode->printDataNode(buffer);
	}

	// Function to PRINT information of Free Blocks  
	void toPrintFreeNodes()
	{
		printf("\n\n\n=======================================");
		printf("\n\n\tStart Location : %d", uiStartLoc);
		printf("\n\n\tEnd Location   : %d", uiEndLoc);
		printf("\n\n=======================================");

		// recursive call to the linked list of free blocks till the NULL
		if(nextDataNode)
			nextDataNode->toPrintFreeNodes();
	}

	// Function to read data from Data Block 
	void readDataNode(void *buffer, void *mainBuffer);
};

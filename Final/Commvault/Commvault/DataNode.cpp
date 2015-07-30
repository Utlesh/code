#include "DataNode.h"
#include <cstdlib>
#include <iostream>
#include <cstdio>
using namespace std;

DataNode :: DataNode(void)
{
	uiStartLoc = 0;				// starting location of Data block
	uiEndLoc = 0;				// ending location of Data Block
	nextDataNode = NULL;		// pointer to next Data Block is initialised to NULL
}

DataNode :: ~DataNode(void){}

// Function to read data from Data Block
void DataNode ::readDataNode(void * buffer, void *mainBuffer)
{
	// Copying data from data BLOCK to data BUFFER 
	memcpy(buffer, (void*)((int)(mainBuffer)+uiStartLoc), uiEndLoc - uiStartLoc + 1);
}

#include "DataNode.h"
#include <cstdio>
using namespace std;

class FileNode
{
public :

	DataNode *ptrToDataNodes;				// Pointer to the First Data Block(Node) of the File
	char *fileName;							// Pointer to the FileName of the File
	FileNode *nextFileNode;					// Pointer to the NEXT FILE NODE
	int fileSize;							// Total Size of a File in (BYTES) 

	FileNode(void);
	~FileNode(void);


	// Function to Print Information of File
	void toPrintFileNode(void* buffer)
	{
		printf("\n\n\n***************START OF FILE**********************");	
		printf("\n\n\tFile Name      : %s", fileName);						
		printf("\n\tFile Size      : %d", fileSize);						

		// Calling print function of First Data Block of a file
		if(ptrToDataNodes)
			ptrToDataNodes->printDataNode(buffer);

		printf("\n\n***************END OF FILE************************");
	}

};

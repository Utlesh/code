#include "VMFT.h"
#define SUCCESS 1
#define NOTFOUND 0
#define ERROR -1
#include <cstdio>
using namespace std;

class VFS
{
public :
	
	void *virtualMainBuffer;				// Pointer to Main Buffer
	DataNode *ptrToFirstFreeMemoryNode;		// Pointer to First Free Node 
	VMFT *ptrVMFT;							// Pointer to VMFT

	VFS(void);
	~VFS(void);

	// To Initialise the File System
	void initFS(int);

	// Function to print information of VMFT 
	void toPrint(void)
	{
		// Calling Print function of VMFT
		ptrVMFT->toPrintVMFTNode(virtualMainBuffer);

		// Calling print function for free blocks
		printf("\n\n\n*********** LINKED LIST OF FREE NODES ************");
		ptrToFirstFreeMemoryNode->toPrintFreeNodes();
		printf("\n\n*************** END OF FREE NODES ****************");
	}

	int createNewFile(char *fileName);
	int writeFile(char *fileName, void * buffer, unsigned int bufferSize, int offset);
	int readFile(char *fileName, void * buffer);
	int deleteFile(char *fileName);
	int renameFile(char *fileName, char *newName);
	unsigned int calcNoOfFreeNodes();
	int append(FileNode *fp, DataNode *lastDp, void *buffer, unsigned int bufferSize, int offset);
};

#include "FileNode.h"
#include <cstdio>
using namespace std;

class VMFT
{
public :

	FileNode *ptrToFirstFileNode;		// Pointer to First File Node
	int numberOfFiles ;					// Total Number of Files present in VMFT(Virtual Master File Table)

	VMFT(void);
	~VMFT(void);

	// Function to Search File with the FileName passed as argument
	FileNode* searchFile(char * fileName);

	// Function to Print VMFT information
	void toPrintVMFTNode(void *buffer)
	{
		// Pointer to First File Node for traversing the list of File Nodes 
		FileNode *fptr = ptrToFirstFileNode;

		printf("\n\n\n==============Total No of Files in MFT===================");
		printf("\n\n\t Number of Files : %d",numberOfFiles);
		printf("\n\n====================== END OF MFT =========================");

		// Iterative traversing to the list of File Nodes
		while(fptr)
		{
			fptr->toPrintFileNode(buffer);		// calling print function of each File Node
			fptr = fptr->nextFileNode;			// pointer jumped to next File Node
		}
	}
};


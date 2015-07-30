#include "VFS.h"
#include <cstdio>
using namespace std;

VFS :: VFS(void)
{
	this -> virtualMainBuffer = NULL;
	this -> ptrToFirstFreeMemoryNode = NULL;
	this -> ptrVMFT = NULL;
}


VFS :: ~VFS(void){}

void VFS :: initFS(int size)
{
	virtualMainBuffer = malloc(size);				// allocating memory of Main Memory Buffer

	memset(virtualMainBuffer,0,size);				// Initialising each byte to null

	ptrToFirstFreeMemoryNode = new DataNode();		// allocation of memory for free block 
	ptrToFirstFreeMemoryNode->uiStartLoc = 0;		// Starting loction of free block = 0
	ptrToFirstFreeMemoryNode->uiEndLoc = size - 1;	// Ending location of free block = size -1

	ptrVMFT = new VMFT();			// allocation of memory for VMFT node and ptrVMFT is a Pointer pointing to this memory
}

// function to calculate total number of free bytes in memory
unsigned int VFS :: calcNoOfFreeNodes()
{
	unsigned int count = 0;			// to store the total number of free bytes
	DataNode *ptrFreeNode = ptrToFirstFreeMemoryNode;	// pointer to traverse the linked list of free blocks
	
	while(ptrFreeNode)
	{
		count += (ptrFreeNode->uiEndLoc - ptrFreeNode->uiStartLoc + 1);
		ptrFreeNode = ptrFreeNode->nextDataNode;
	}

	return count;
}

// function to create new file
int VFS :: createNewFile(char *fileName)
{
	FileNode *fp;

	// If first file node is empty
	if(!ptrVMFT->ptrToFirstFileNode)
	{
		ptrVMFT->ptrToFirstFileNode = new FileNode();
		fp = ptrVMFT->ptrToFirstFileNode;
	}

	else
	{
		fp = ptrVMFT->ptrToFirstFileNode;

		// if new fileName already exists in current linked list of files in vmft
		if(strcmp(fp->fileName, fileName) == 0)
		{
			printf("\n\nFile  not created. File with same name is already preasent\n\n"); 
			return ERROR;
		}

		while(fp->nextFileNode)
		{
			fp = fp->nextFileNode;

			// if new fileName already exists in current linked list of files in vmft
			if(strcmp(fp->fileName, fileName) == 0)
			{
				printf("\n\nFile  not created. File with same name is already preasent\n\n"); 
				return ERROR;
			}
		}

		fp->nextFileNode = new FileNode();
		fp = fp->nextFileNode;
	}
	
	// after successful creation of new file set the filename of file
	memcpy(fp->fileName,fileName,sizeof(fileName)+2);
	ptrVMFT ->numberOfFiles += 1;
	printf("\n\n\t \"%s\" is created successfully.\n\n",fileName);
	return SUCCESS;
}

// function to rename file with new fileName
int VFS :: renameFile(char *fileName, char *newName)
{
	FileNode * fp = ptrVMFT->ptrToFirstFileNode;

	// traversing all  file nodes till the NULL
	while(fp)
	{
		if(strcmp(fp->fileName, fileName) == 0)
		{
			// if file is found then change the fileName
			if(ptrVMFT->searchFile(newName)){
				printf("\n\n \"%s\" file already exists. So we cant change filename of  \"%s\" \n\n", 
					newName, fileName);
				return ERROR;
			}

			fp->fileName = new char[strlen(newName)];
			memcpy(fp->fileName,(void *)newName,sizeof(newName)+2);
			printf("\n\n File \"%s\" is renamed to \"%s\" successfully.", fileName, newName);
			return SUCCESS;
		}
		fp = fp->nextFileNode;
	}

	// if file is not found then return error
	printf("\n\nFile  not found\n\n"); 
	return NOTFOUND;
}

int VFS :: append(FileNode *fp, DataNode *ptrLastDataNode, void *buffer, unsigned int bufferSize, int offset)
{
	// if checking whether sufficient space is available or not
	if(bufferSize > calcNoOfFreeNodes()) {
		cout<< "Required free space is not available.\n";
		return ERROR;
	}

	DataNode *dp;
	DataNode *ptrFreeNode = ptrToFirstFreeMemoryNode;
	unsigned int range = 0, sum = 0;
	int totalPrint = 0;
	while(ptrFreeNode)
	{
		range = (ptrFreeNode->uiEndLoc - ptrFreeNode->uiStartLoc + 1);	// size of data block
		sum += range;					// offset of file till the end of this data block 

		if(bufferSize < range)
		{
			memcpy((void*)((int)virtualMainBuffer + ptrFreeNode->uiStartLoc), (void*)((int)buffer+totalPrint), bufferSize);
			
			dp = new DataNode();
			DataNode *freeDp = new DataNode();

			// a new Free DataNode is created with new Start location and 
			// new End location and with next free node as the previous one.
			freeDp->uiStartLoc = ptrFreeNode->uiStartLoc + bufferSize ;			
			freeDp->uiEndLoc = ptrFreeNode->uiEndLoc;
			freeDp->nextDataNode = ptrFreeNode->nextDataNode;

			// Now the first virtual FREE Memory node is assigned 
			ptrToFirstFreeMemoryNode = freeDp;

			// assignin the values of members of the data nodes
			dp->uiEndLoc = freeDp->uiStartLoc - 1;
			dp->uiStartLoc = ptrFreeNode->uiStartLoc;
			
			if(!fp->ptrToDataNodes)
			{
				fp->ptrToDataNodes = dp;		// appending at the start of file or empty  file
			}

			else
			{
				ptrLastDataNode -> nextDataNode = dp;	// appending at the end of file
			}

			fp->fileSize += bufferSize;
			delete(ptrFreeNode);
			
			return SUCCESS;
		}

		else
		{
			dp = ptrFreeNode;		// assigning next free node as data node of file

			memcpy((void*)((int)virtualMainBuffer + dp->uiStartLoc), (void*)((int)buffer+totalPrint), range);
			
			
			if(!fp->ptrToDataNodes)				
			{
				fp->ptrToDataNodes = dp;		// appending at the start of file or empty  file
			}

			else
			{
				ptrLastDataNode -> nextDataNode = dp;		// appending at the end of file
			}

			ptrLastDataNode = dp;			// updating the pointer to last DataNode for the current file
			totalPrint += range;			// total number of written characters
			fp->fileSize += range;			// increasing the file size according to the number of characters 
											//written on the current file
			bufferSize = bufferSize - range; // reducing the buffersize according to the written characters in file.
			ptrFreeNode = ptrFreeNode->nextDataNode;	// moving to the next free node to write remaining buffer
		}
	}

}

int VFS :: writeFile(char *fileName, void *buffer, unsigned int bufferSize, int offset)
{
	// search file with fileName = argument(fileName) 
	FileNode *fp = ptrVMFT->searchFile(fileName);
	
	if(fp)
	{
		
		if(offset > fp->fileSize)
		{
			cout<< "Given offset "<< offset <<" is greater than the file size "<<fp->fileSize 
				<<" of file : "<< fp->fileName <<"\n\n";
			return ERROR;
		}


		DataNode *dp = fp->ptrToDataNodes;
		DataNode *ptrLastDataNode = dp;
		unsigned int sum = 0, range = 0, totalPrint = 0;
		int vsize, diff;
		while(dp)
		{
			range = (dp->uiEndLoc - dp->uiStartLoc + 1);	// size of data block
			sum += range;									// offset of file till the end of this data block 

			// if data overwrite
			if(sum > offset && offset != -1)
			{
				diff = sum - offset; 

				// if size of remaining buffersize < range of data block
				if(offset + bufferSize <= sum)
				{
					vsize = bufferSize;
					memcpy((void*)((int)virtualMainBuffer + dp->uiStartLoc+range-diff), (void*)((int)buffer + totalPrint), vsize);
					return SUCCESS;
				}

				else
				{
					// if size of data block overlaps two or more data blocks during overwrite
					vsize = diff;
					bufferSize = bufferSize - diff;
					offset = sum;
					memcpy((void*)((int)virtualMainBuffer + dp->uiStartLoc+range-diff), (void*)((int)buffer + totalPrint), vsize);
					totalPrint += vsize;
				}
				
			}
			ptrLastDataNode = dp;
			dp = dp->nextDataNode;
		}

		if(bufferSize)
		{
			// remaining file data is appended at the end of file in memory
			append(fp, ptrLastDataNode, (void*)((int)buffer + totalPrint), bufferSize, offset);
		}

		return SUCCESS;
		
	}

	// file not found
	printf("\n\nFile not found\n\n"); 
	return NOTFOUND;
}

int VFS :: readFile(char *fileName, void * buffer)
{
	FileNode *fptr = ptrVMFT->searchFile(fileName);

	if(fptr)
	{
		DataNode *dptr = fptr->ptrToDataNodes;
		int totalBytesRead = 0;

		while(dptr)
		{
			dptr->readDataNode((void*)((int)buffer+totalBytesRead), virtualMainBuffer);
			totalBytesRead += dptr->uiEndLoc - dptr->uiStartLoc + 1;
			dptr = dptr->nextDataNode;
		}

		memset((void*)((int)buffer+totalBytesRead), 0, 1);
		return totalBytesRead;
	}

	printf("\n\nFile  not found\n\n"); 
	return ERROR;
}

int VFS :: deleteFile(char *fileName)
{
	FileNode *fptr = ptrVMFT->ptrToFirstFileNode;
	FileNode *lastFptr = fptr;		//pointer to previous file node

	while(fptr)
	{
		if(strcmp(fptr->fileName, fileName) == 0)
		{
			DataNode *ptrFreeNodes = ptrToFirstFreeMemoryNode;

			while(ptrFreeNodes->nextDataNode)
				ptrFreeNodes = ptrFreeNodes->nextDataNode;

			// linking last free block to first data block of current file
			// hence all data blocks are changed to free blocks  
			ptrFreeNodes->nextDataNode = fptr->ptrToDataNodes;
			fptr->ptrToDataNodes = NULL;
		
			break;
		}
		lastFptr = fptr;
		fptr = fptr ->nextFileNode;
	}

	if(!fptr){
		printf("\n\nFile  not found\n\n"); 
		return ERROR;
	}

	// if first file is to be deleted
	if(fptr == ptrVMFT->ptrToFirstFileNode)
	{
		ptrVMFT->ptrToFirstFileNode = fptr->nextFileNode;
	}

	else
	{
		lastFptr->nextFileNode = fptr->nextFileNode;
	}
	
	// file node is deleted
	delete(fptr);
	ptrVMFT->numberOfFiles -= 1;
	printf("\n\nFile with filename \"%s\" is deleted Successfully.\n\n",fileName);
	return SUCCESS;
}


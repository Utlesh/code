#include "FileNode.h"
#include <cstdlib>
using namespace std;

FileNode :: FileNode(void):fileSize(0)
{
	ptrToDataNodes = NULL;			
	fileName = new char[100];		
	nextFileNode = NULL;			
}


FileNode :: ~FileNode(void){}

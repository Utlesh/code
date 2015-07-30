
#include "VFS.h"
#include <string.h>
#include <cstdio>

using namespace std;

char *str1 = "My name is V Krishna.";
char *str2 = "Studies Computer Engineering.";
char *str3 = "in Army Institute of Technology.";
char *str4 =  "Intersted in programming.";
char *str5 = "Good Luck.";

void * buffer = new char[10];

int main()
{
	VFS *ptrVFS = new VFS();
	int offset, bytes;
	ptrVFS->initFS(1024 * 4096);

	ptrVFS->createNewFile("file1");
	ptrVFS->createNewFile("file2");

	offset = 0;
	ptrVFS->writeFile("file1", str1, strlen(str1), offset);
	offset += strlen(str1);
	ptrVFS->writeFile("file1", str2, strlen(str2), offset);
	ptrVFS->writeFile("file2", str3, strlen(str3), 0);
	ptrVFS->toPrint();

	ptrVFS->deleteFile("file2");
	ptrVFS->toPrint();

	ptrVFS->writeFile("file1",str4, strlen(str4), -1);
	ptrVFS->toPrint();

	ptrVFS->writeFile("file1",str5, strlen(str5), 10);
	ptrVFS->toPrint();

	printf("\n\n=============== READING A FILE ============\n");
	bytes = ptrVFS->readFile("file1", buffer);
	printf("\n\nRead Bytes = %d\n\nRead Data = %s\n",bytes,buffer);
	printf("\n\n===========================================\n");

	ptrVFS->renameFile("file1", "file2");

	ptrVFS->deleteFile("file2");
	ptrVFS->toPrint();

	
	ptrVFS->toPrint();

	return 0;
}
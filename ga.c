#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include "win.h"
#include <tchar.h>

TCHAR szName[]=TEXT("Global\\MyFileMappingObject");

#define BUF_SIZE 32
int galoop(){
	
   HANDLE hMapFile;
   LPTSTR pBuf;
	int i = 0 ;
	char c;
   hMapFile = CreateFileMapping(
                 INVALID_HANDLE_VALUE,    // use paging file
                 NULL,                    // default security
                 PAGE_READWRITE,          // read/write access
                 0,                       // maximum object size (high-order DWORD)
                 BUF_SIZE,                // maximum object size (low-order DWORD)
                 szName);                 // name of mapping object

   if (hMapFile == NULL)
   {
		printf(TEXT("Could not create file mapping object (%d).\n"),
             GetLastError());
      return 1;
   }
   pBuf = (LPTSTR) MapViewOfFile(hMapFile,   // handle to map object
                        FILE_MAP_ALL_ACCESS, // read/write permission
                        0,
                        0,
                        BUF_SIZE);
	


   if (pBuf == NULL)
   {
        printf(TEXT("Could not map view of file (%d).\n"),
             GetLastError());

       CloseHandle(hMapFile);
      return 1;
   }
	pBuf[7]=0;
	pBuf[0]=0;
while(1){
	
	if(pBuf[6] == 0){
		pBuf[0] ^= 1;
		printf("\n send msg ........\n");
		pBuf[6] = 1;
		
	}
   if(pBuf[7] == 1){
	printf("\n receive ack...\n");
	
	pBuf[7] = 0;
	pBuf[6] = 0;
   }
   if(pBuf[6] == 1 && pBuf[7] == 0)
	   printf("\r wait ack ........");
   else
	   printf("\r wait data ........");
   sleep(1);
}
   UnmapViewOfFile(pBuf);

   CloseHandle(hMapFile);

   return 0;
	
	
}

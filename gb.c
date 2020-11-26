#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#pragma comment(lib, "user32.lib")
#define BUF_SIZE 32
TCHAR szName[]=TEXT("Global\\MyFileMappingObject");

int galoop()
{
   HANDLE hMapFile;
   LPTSTR pBuf;
   char c;
   

   hMapFile = OpenFileMapping(
                   FILE_MAP_ALL_ACCESS,   // read/write access
                   FALSE,                 // do not inherit the name
                   szName);               // name of mapping object

   if (hMapFile == NULL)
   {
      _tprintf(TEXT("Could not open file mapping object (%d).\n"),
             GetLastError());
      return 1;
   }

   pBuf = (LPTSTR) MapViewOfFile(hMapFile, // handle to map object
               FILE_MAP_ALL_ACCESS,  // read/write permission
               0,
               0,
               BUF_SIZE);
	

   if (pBuf == NULL )
   {
      _tprintf(TEXT("Could not map view of file (%d).\n"),
             GetLastError());

      CloseHandle(hMapFile);

      return 1;
   }
   
	while(1){
	
   if(pBuf[6]== 1){
	   printf("\n receive data %d & reply ack...\n",pBuf[0]);
	   pBuf[7] = 1;
	   
   
   }
   if(pBuf[7]==2)
	   break;
   printf("\r wait data ...");
   sleep(5);
}

   UnmapViewOfFile(pBuf);

   CloseHandle(hMapFile);

   return 0;
}
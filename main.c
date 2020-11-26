#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include "win.h"
static int ret = 0;
int main(){
	
	ret = galoop();
	if(ret == 1 ){
		printf("ga_err\r\n");
	}
	
	//gbloop();
	
}
int is_win(char * pBuf){
	
	if(pBuf[8] == pBuf[9] && pBuf[8] == pBuf[10] && pBuf[8]!=0){
		printf("%d p win\n",pBuf[8] == 'X'?1:2);
		return pBuf[8] == 'X'?1:2;
	}
	if(pBuf[8] == pBuf[11] && pBuf[8] == pBuf[14] && pBuf[8]!=0){
		printf("%d p win\n",pBuf[8] == 'X'?1:2);
		return pBuf[8] == 'X'?1:2;
	}
	if(pBuf[8] == pBuf[12] && pBuf[8] == pBuf[16] && pBuf[8]!=0){
		printf("%d p win\n",pBuf[8] == 'X'?1:2);
		return pBuf[8] == 'X'?1:2;
	}
	if(pBuf[9] == pBuf[12] && pBuf[9] == pBuf[15] && pBuf[9]!=0){
		printf("%d p win\n",pBuf[9] == 'X'?1:2);
		return pBuf[9] == 'X'?1:2;
	}
	if(pBuf[10] == pBuf[13] && pBuf[16] == pBuf[10] && pBuf[10]!=0){
		printf("%d p win\n",pBuf[10] == 'X'?1:2);
		return pBuf[10] == 'X'?1:2;
	}
	if(pBuf[10] == pBuf[12] && pBuf[14] == pBuf[10] && pBuf[10]!=0){
		printf("%d p win\n",pBuf[10] == 'X'?1:2);
		return pBuf[10] == 'X'?1:2;
	}
	if(pBuf[11] == pBuf[12] && pBuf[13] == pBuf[11] && pBuf[11]!=0){
		printf("%d p win\n",pBuf[11] == 'X'?1:2);
		return pBuf[11] == 'X'?1:2;
	}
	if(pBuf[14] == pBuf[15] && pBuf[16] == pBuf[14] && pBuf[14]!=0){
		printf("%d p win\n",pBuf[14] == 'X'?1:2);
		return pBuf[14] == 'X'?1:2;
	}
	return 0;

}
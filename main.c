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

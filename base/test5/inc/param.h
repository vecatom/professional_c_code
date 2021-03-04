
#ifndef _PARAM_H
#define _PARAM_H
#include<stdio.h>

#define __INFO(fmt,...) do{\
	printf("[%s]<%s>(%d):",__FILE__,__func__,__LINE__);\
	printf(fmt,__VA_ARGS__);\
}while(0)

#define mkstr(symbol) #symbol
#define _error(exp,escap_lable,fmt,...) do{\
	if(exp){\
		__info(" *** error occured ***| %s ",mkstr(exp));\
		printf(fmt,__VA_ARGS__);\
		got escape_lable;\
	}\
}while(0)

#define _pos() __info("%s","\n")

typedef int(*pCHKPARAMFUNC)(int argc,char *argv[]);


int chk_param(int argc,char *argv[]);

#endif


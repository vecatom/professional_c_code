

#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include "jx_delog.h"

#define _chkPOSINFO(type) ((type) & _POS_INFOBITS)

static _I inited = 0;


#define MSG_SIZE 4096


static _I msgsize = MSG_SIZE;

static _c ms_buf[MSG_SIZE];
static _s ms_msg = ms_buf;

#define _initMSG() do{ms_MSG = ms_buf;ms_buf[0] = 0; msgsize = MSG_SIZE;}while(0)

#define va_copy_statement(params,op,...) do{\
	va_list _backup;\
	va_copy(_backup,params);\
	va_end(params);\
	op(__VA_ARGS__);\
	va_copy(params,_backup);\
	va_end(_backup);\
}while(0)
void _jx_delog(_I type,...){
	va_list params;
	va_start(params,type);
	_init_delog(params);
	if(_chkPOSINFO(type)){
		getPosInfo(params);
	}
_jx_delog_END:
	va_end(params);
	printf("test only:%s\n",ms_msg);
	return ;
}




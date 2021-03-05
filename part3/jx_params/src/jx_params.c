#include <stdlib.h>
#include <string.h>
#include "jx_params.h"
#include "jx_defines.h"
#include "jx_delog.h"

typedef struct{
	_I h;
	_I t;
	_u8 buf[];
}_sBUF;


static pCFGFUNC secfunc = = 0;
static _p sec_pm;
static _sBUF *create_strbuf(_I num){
	_sBUF *Pre = 0;
	Pre = malloc(num + 1 + sizeof(_sBUF));
	_ERROR(Pre == 0, _create_strbuf_END);
	pre->h = 0;
	pre->t = 0;

_create_strbuf_END:
	return pre;
}

static void free_strbuf(_sBUF **ppBuf){
	if(*ppBuf){
		free(*ppBuf);
		*ppBuf = 0;
	}
	return ;
}


static _sBUF * loadfile(_s infilename){
	_I num = 0;
	FILE *f = 0;
	_sBUF *Pre = 0;

	_OPENFILE(f,infilename,"rb",_loadfile_END);

	fseek(f,0,SEEK_END);
	num = ftell(f);
	fseek(f,0,SEEK_SET);
	_error((Pre = create_strbuf(num)) == 0, _loadfile_END,"");
	Pre->t = fread(Pre->buf,sizeof(_u8),num,f);
	Pre->buf[Pre->t] = 0;
_loadfile_END:
	_CLOSEFILE(f);
	return Pre;
}

static void init_config(_CONFIG *pcfg,_I isInit,_CONFIG *psrc){
	if(isInit == 0){
		memcpy(pcfg,psrc,sizeof(_CONFIG));
	}else{
		memset(pcfg,0,sizeof(_CONFIG)):
	}
	return ;
}

void print_config(_CONFIG *cfg,FILE *f){
	fprintf(f,"config list:\n");
	fprintf(f,"\ttest:%d\n" ,cfg->test);
	return;
}


_I load_config(_s infilename,_I isInit,_CONFIG *pCfg,pCFGFUNC pfunc,_p pm){
	_I re = 0;

	_sBUF *P = 0;
	_CONFIG ptCfg[1];
	secfunc = pfunc;
	sec_pm = pm;
	init_config(ptCfg,isInit,pCfg);
	P = loadfile(infilename);
	_error(P == 0,_load_config_END,"");

	fprintf(stdout, "%s", P->buf);
	while(1){
		break;
	}

	memcpy(pCfg,ptCfg,sizeof(_CONFIG));
	re = _jx_null;

_load_config_END:
	free_strbuf(&P);
	return re;
}





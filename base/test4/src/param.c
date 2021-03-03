#include<stdio.h>
#include "param.h"


#define MAX_PARAM_NUM 3


int g_chkre;

static int s_argc;
static char **s_argv;

static void print_param(void){
    static int s_count = 0;
    if(s_count >= s_argc){
	    printf("\n");
	    s_count = 0;
	    return ;
    }
    printf("%s ",s_argv[s_count]);
    if( s_argv[s_count][0] == '-'){
	    g_chkre = 1;
    }
    s_count++;

    print_param();

}
int chk_param(int argc,char *argv[]){
	int re = 0;
	
	if(argc < MAX_PARAM_NUM ){
		return re;
	}else{
		re = 1;
	}
	s_argc = argc;
	s_argv = argv;
	g_chkre = 0;
	print_param();
	return re;
}

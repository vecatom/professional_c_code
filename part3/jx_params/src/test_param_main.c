#include "jx_types.h"
#include "jx_defines.h"
#include "jx_params.h"

_i32 main(_i32 argc,_s argv[]){
	_i32 re = 1;
	_CONFIG cfg[1];
	_chkargc(2,"need config filename",_main_END);
	re = load_config(argv[1],1,cfg,0,0);

_main_END:
	return re;
}

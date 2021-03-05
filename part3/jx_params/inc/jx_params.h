#define _JX_PARAMS_H
#include <stdio.h>
#include "jx_types.h"
#include "jx_defines.h"

// ins_typedef
typedef struct{
	_I test;
}_CONFIG;

// ins_def
typedef _I (*pCFGFUNC)(_CONFIG *pCfg,_p pm);

// ins_func_declare
_I load_config(_s infilename,_I isInit,_CONFIG* pCfg,pCFGFUNC pfunc,_p pm;
void print_config(_CONFIG *cfg,FILE *f);

#endif /* _JX_PARAMS_H*/

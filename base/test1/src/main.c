

int chk_param(int argc,char *argv[]);

int main(int argc ,char *argv[]){
	return chk_param(argc ,argv);
}


#define MAX_PARAM_NUM 3
int chk_param(int argc,char *argv[]){
	if(argc < MAX_PARAM_NUM ){
		return 0;
	}else{
		return 1;
	}
}


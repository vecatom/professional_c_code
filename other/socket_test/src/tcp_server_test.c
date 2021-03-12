#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#define PORT 8082
#define BUFSIZE 512

char buf[BUFSIZE+1];

void* func(void* x){
	
	printf("enter thread!\r\n");
	int new_fd = *((int*)x);
	while(1){
		int  z = read(new_fd,buf,BUFSIZE);
		if(z==0){
			printf("client close !");
			break;
		}
		buf[z]='\0';
		printf("%s\r\n",buf);
	}
}


int newfd[512];
int inewfd=0;

int main(){
	int sockfd=socket(AF_INET,SOCK_STREAM,0);

	struct sockaddr_in svraddr;

	svraddr.sin_family=AF_INET;
	svraddr.sin_port=htons(PORT);
	inet_aton("0.0.0.0",&svraddr.sin_addr);

	int ret = bind(sockfd,(struct sockaddr*)&svraddr,sizeof(svraddr));

	if(ret<0){
		printf("error bind!\r\n");
		exit(-1);
	}

	listen(sockfd,128);
	while(1){
		newfd[inewfd++]=accept(sockfd,NULL,NULL);
		pthread_t ntid;
		pthread_create(&ntid,NULL,func,(void*)&(newfd[inewfd-1]));
	}
}



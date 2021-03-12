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

int main(){

	int sockfd=socket(AF_INET,SOCK_STREAM,0);

	struct sockaddr_in svraddr;

	svraddr.sin_family=AF_INET;
	svraddr.sin_port=htons(PORT);

	inet_aton("127.0.0.1",&svraddr.sin_addr);


	connect(sockfd,(struct sockaddr*)&svraddr,sizeof(svraddr));

	while(1){
		scanf("%s",buf);
		write(sockfd,buf,strlen(buf));
	}
}

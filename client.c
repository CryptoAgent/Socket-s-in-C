#include "stdio.h"
#include "stdlib.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include "unistd.h"

int main(){

	int net_sock = socket(AF_INET,SOCK_STREAM,0); 	
	struct sockaddr_in serv;
	serv.sin_family=AF_INET;
	serv.sin_port=htons(8080);
	serv.sin_addr.s_addr=INADDR_ANY;
	int stage = connect(net_sock,(struct sockaddr*)&serv,sizeof(serv));
	if(stage == -1){
		printf("Can't connect\r\n");
	}
	char data[1024];
	recv(net_sock,&data,1024,0);
	printf("%s\n", data);
	close(net_sock);
	return 0;
}
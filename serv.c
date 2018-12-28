#include "stdio.h"
#include "stdlib.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include "unistd.h"

int main(){

	char mess[1024]={"www.youtube.com/watch?v=LDU_Txk06tM"};	
	int net_sock = socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in serv;
	serv.sin_family=AF_INET;
	serv.sin_port=htons(8080);
	serv.sin_addr.s_addr=INADDR_ANY;
	bind(net_sock,(struct sockaddr*)&serv,sizeof(serv));
	listen(net_sock,3);
	int client = accept(net_sock,NULL,NULL);
	send(client,mess,1024,0);
	close(net_sock);
	return 0;
}
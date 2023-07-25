#include<stdio.h>
//header file for commonly using input and output functions (printf and scanf)

#include<stdlib.h>
// has predefined macros and mostly used to have list of general functions used (atoi)

#include<string.h>
// consists of string functions (strlen,strcmp)

#include<unistd.h>
//consists of miscallaneous symbols needed for sys/types.h

#include<sys/types.h>
//consists of definitions of a number of datatypes used in system call
//this is mandatory header file to use sys/socket.h and netinet/in.h

#include<sys/socket.h>
//defines the socket address

#include<netinet/in.h>
//consists of structure and constants need for socket address

#include<netdb.h>

void error(const char *msg){
	perror(msg);
	exit(0);
}

int main(int argc, char *argv[])
{
	int sockfd, portno, n;
	struct sockaddr_in serv_addr; // 
	struct hostent *server;
	char buffer[256];

	if(argc < 3){
		fprintf(stderr,"uasge %s hostname port\n",argv[0]);
		exit(0);
	}

	portno = atoi(argv[2]);

	sockfd = socket(AF_INET, SOCK_STREAM, 0); // address family(IPV4), TCP/UDP, Default for TCP protocol 
	if(sockfd < 0) { error("Error in opening network socket");}

	server = gethostbyname(argv[1]);

	if(server ==  NULL){
		fprintf(stderr,"ERROR,no such host\n");
		exit(0);
	}

	bzero((char *)&serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	bcopy((char *)(server->h_addr), (char *)&serv_addr.sin_addr.s_addr, server->h_length);
	serv_addr.sin_port = htons(portno);

	if(connect(sockfd, (struct sockaddr *)(&serv_addr), sizeof(serv_addr)) < 0) // connect function handles the return type resulting in the connection status.
		error("ERROR connecting");
	printf("Client :");

	while(1){
		bzero(buffer, 256);
		fgets(buffer, 255, stdin);
		n = write(sockfd, buffer, strlen(buffer));
		
		if(n < 0)
			error("ERROR writting to socket");
		
		bzero(buffer, 256);
		n = read(sockfd, buffer, 255);
		
		if(n < 0)
			error("ERROR reading from socket");
		printf("Server : %s\n",buffer);
		int i = strncmp("Bye", buffer, 3);
		if (i == 0)
			break;
	}
	return 0;
}

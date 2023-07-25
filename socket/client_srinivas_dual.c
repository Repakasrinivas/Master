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

#include<pthread.h>

int sockfd, newsockfd ,portno, n;
struct sockaddr_in serv_addr; // 
struct hostent *server;
char recv_buffer[256], send_buffer[256];

void error(const char *msg){
	perror(msg);
	exit(0);
}

int main(int argc, char *argv[])
{
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
	int pid = fork();
	if(pid == 0)
	{
		while(1)
		{
        		int n;
		        bzero(&send_buffer, 256);
		        fgets(send_buffer, 255, stdin);
		        n = send(newsockfd, send_buffer, strlen(send_buffer)+1, 0);
		        if(n < 0) { error("error on writing"); }
			int i = strncmp("Bye", send_buffer, 3);
			if (i == 0)
				break;
		}
	}
	else {
		while(1){
        		int n;
		        n = recv(newsockfd, recv_buffer, 256, 0);
		        if(n < 0) { error("error on reading"); }
		        printf("Client : %s\n", recv_buffer);
		        bzero(recv_buffer, 255);
			int i = strncmp("Bye", recv_buffer, 3);
			if (i == 0)
				break;
		}
	}
	close(sockfd);
	return 0;
}

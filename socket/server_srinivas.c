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


void error(const char *msg){
	perror(msg);
	exit(0);
}

int main(int argc, char *argv[]){
	if(argc < 2){
		fprintf(stderr,"port no is not specified\n");
		exit(1);
	}
	
	int sockfd, newsockfd, portno, n;
	char buffer[256];

	struct sockaddr_in serv_addr, cli_addr;
	socklen_t clilen;
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if(sockfd < 0) { error("Error in opening socket"); }

	bzero((char *)&serv_addr, sizeof(serv_addr));
	portno = atoi(argv[1]);
	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);

	printf("Server waiting from client message ...!!\n");
	if(bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) { error("binding failed"); }

	listen(sockfd, 10);
	clilen = sizeof(cli_addr);

	newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);

	if(newsockfd < 0){ error("error in network accept"); }

	while(1)
	{
		bzero(buffer, 256);
		n = read(newsockfd, buffer, 256);

		if(n < 0) { error("error on reading"); }
		printf("Client : %s\n", buffer);
		bzero(buffer, 255);
		fgets(buffer, 255, stdin);

		n = write(newsockfd, buffer, strlen(buffer));

		if(n < 0) { error("error on writing"); }

		int i = strcmp("bye", buffer);

		if(i == 0) { break; }
	}
	close(sockfd);
	close(newsockfd);
	return 0;

}

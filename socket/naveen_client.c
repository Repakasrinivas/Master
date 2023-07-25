#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#define SIZE 1024
void *thread_function(void *arg);
int main()
{
    int res;
     pthread_t a_thread;
    void *thread_result;
 
     res = pthread_create(&a_thread, NULL, thread_function, NULL);
     if (res != 0) {
         perror("Thread creation failed");
         exit(EXIT_FAILURE);
     }
   
    res = pthread_join(a_thread, &thread_result);
     if (res != 0) 
     {
         perror("Thread join failed");
         exit(EXIT_FAILURE);
     }
     printf("Thread joined\n");
     exit(EXIT_SUCCESS);
 }

void *thread_function(void *arg)
{
    int sockfd;
    int len;
    struct sockaddr_in address;
    int result;
    char buff[SIZE];
    int n;
    
     /*  Create a socket for the client.  */

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

/*  Name the socket, as agreed with the server.  */

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port =htons(9734);
    len = sizeof(address);

/*  Now connect our socket to the server's socket.  */

    result = connect(sockfd, (struct sockaddr *)&address, len);

    if(result == -1) {
        perror("oops: client2");
        exit(1);
    }
    while(1)
    {
	printf("Enter a message: ");
	n=0;

	while((buff[n++] = getchar())!='\n');
	write(sockfd, buff, sizeof(buff));
        read(sockfd, buff, sizeof(buff));
        printf("from server:%s\n", buff);
     }
     close(sockfd);
     pthread_exit(NULL);
}


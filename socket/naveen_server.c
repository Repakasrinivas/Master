#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

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
     int server_sockfd, client_sockfd;
     int server_len, client_len;
     struct sockaddr_in server_address;
     struct sockaddr_in client_address;
     char buff[SIZE];
     int n;
 
      /*  Create an unnamed socket for the server.  */
 
     server_sockfd = socket(AF_INET, SOCK_STREAM, 0);

     /*  Name the socket.  */ 
     server_address.sin_family = AF_INET;
     server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
     server_address.sin_port = htons(9734);
     server_len = sizeof(server_address);
     bind(server_sockfd, (struct sockaddr *)&server_address, server_len);
 
  /*  Create a connection queue and wait for clients.  */
 
     listen(server_sockfd, 5);
     printf("Server waiting\n");
     client_len = sizeof(client_address);

     client_sockfd = accept(server_sockfd,(struct sockaddr *)&client_address, &client_len);
     if(client_len < 0)
     {
	printf("Server accept failed\n");
     }
     else
     {
	printf("Server accept the client\n");
     }
    while(1)
    {
        /* read message from client and copy in it buffer */
	read(client_sockfd, buff, sizeof(buff));
	/* print buffer which contains the client contents */
	printf("From client: %s\t to client: ",buff);
	n=0;
	/* copy server message in the buffer*/
	while((buff[n++]= getchar())!= '\n');
	/* send server message in the buffer */
	write(client_sockfd, buff, sizeof(buff));
   }
   pthread_exit(NULL);
   close(server_sockfd);
}


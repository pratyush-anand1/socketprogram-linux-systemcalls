#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
int main() {
    //variables
    int serversockfd,clientsockfd;
    struct sockaddr_in serveraddress,clientaddress;
    int clientaddr_length;
    //socket creation
    serversockfd=socket(AF_INET,SOCK_STREAM,0);
    if(serversockfd==-1) {
      printf("failed to create a socket\n");
      exit(1);
    } else {
        printf("socket : %d \n",serversockfd);
    }
    //bind
   bzero(&serveraddress,sizeof(serveraddress)); //initially serveraddress shall contain no value
   serveraddress.sin_family = AF_INET;
   serveraddress.sin_addr.s_addr = htonl(INADDR_ANY);
   serveraddress.sin_port = htons(1234);
   if(bind(serversockfd,(struct sockaddr*) &serveraddress,sizeof(serveraddress)) != 0) {
    printf("binding failed \n");
    exit(1);
   } else {
    printf("binding successful \n");
   }
   //listen
   if(listen(serversockfd,1) != 0) {
    printf("Not listening \n");
    exit(1);
   } else {
    printf("server listening \n");
   }
   //accepting 
   clientaddr_length = sizeof(clientaddress);
   bzero(&clientaddress,sizeof(clientaddress));
   clientsockfd = accept(serversockfd,(struct sockaddr*) &clientaddress,clientaddr_length);
   if(clientsockfd == -1) {
      printf("failed to accept \n");
      exit(1);
   } else {
    printf("accepted \n");
   }
   //communication-->write
   char* msg = "socket programming in C";
   write(clientsockfd,msg,strlen(msg));
   printf("sent : %s \n",msg);
   //closing
   close(clientsockfd);
   printf("closed client socket \n");
   close(serversockfd);
   printf("closed server socket \n");
   return 0;
}
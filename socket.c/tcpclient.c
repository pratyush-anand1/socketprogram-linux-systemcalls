#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
int main() {
    //variables
    int sockfd;
    struct sockaddr_in serveraddress;
    //socket creation
    sockfd = socket(AF_INET,SOCK_STREAM,0);
     if(sockfd==-1) {
      printf("failed to create a socket\n");
      exit(1);
    } else {
        printf("socket : %d \n",sockfd);
    }
   //bind
   bzero(&serveraddress,sizeof(serveraddress)); //initially serveraddress shall contain no value
   serveraddress.sin_family = AF_INET;
   serveraddress.sin_addr.s_addr = inet_addr("127.0.0.1");
   serveraddress.sin_port = htons(1234);
   if(bind(sockfd,(struct sockaddr*) &serveraddress,sizeof(serveraddress))== -1) {
    printf("binding failed \n");
    exit(1);
   } else {
    printf("binding successful \n");
   }
   //communication --> read
   char buf[128];
   read(sockfd,buf,sizeof(buf));
   printf("recieved : %s \n",buf);
   //close
   close(sockfd);
   return 0;
}
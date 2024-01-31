#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
int main() {
    char server_message[256] = "socket programming in C";
    int server_socket = socket(AF_INET,SOCK_STREAM,0); //CREATING SERVER SOCKET
    //DEFINE THE SERVER ADDRESS
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;
    //BIND THE IP AND PORT TO THE SERVER SOCKET
    bind(server_socket,(struct sockadd*)& server_address, sizeof(server_address));
    //LISTEN AT THE PORT 
    listen(server_socket,5);
    //accept the incoming connection from the client
    int client_sock;
    client_sock = accept(server_socket,NULL,NULL);
    //send the message to client address
    send(client_sock,server_message,sizeof(server_message),0);
    close(server_socket);
    return 0;
}
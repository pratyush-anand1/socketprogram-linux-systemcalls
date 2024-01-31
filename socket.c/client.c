#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
int main() {
    //create socket
    int network_socket;
    network_socket = socket(AF_INET,SOCK_STREAM,0);
    //specify the address of the socket
    struct sock_addr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr=INADDR_ANY;
    //connection request
    int connection_status;
    connection_status=connect(network_socket,(struct sockadd*) & server_address , sizeof(server_address));
    if(connection_status==-1) {
        printf("error in connection!!!\n");
    }
    //recieve the data from server
    char msg[256];
    recv(network_socket,&msg,sizeof(msg),0);
    printf("server sends the message--> %s\n",msg);
    close(network_socket);
    return 0;
}
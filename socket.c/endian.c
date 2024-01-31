#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
int main(int argc , char *argv[]) {
    unsigned short host_port = 0x1234; //1234h
    unsigned short net_port;
    unsigned long host_address = 0x12345678; //dividing it into pairs and then replacing MSB and LSB for further process
    unsigned long net_address;
    net_port = htons(host_port); //0x3412
    net_address = htonl(host_address);  //0x78563412
    printf("host ordered port %#x \n",host_port);
    printf("Network ordered port %#x \n",net_port);
    printf("host ordered address %#lx \n",host_address);
    printf("Network ordered address %#lx \n",net_address);
    unsigned long host_address2 = ntohl(net_address); //0x12345678
    printf("Network ordered address after conversion is %#lx \n",host_address2);
    return 0;
}
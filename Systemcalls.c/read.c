#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
void main() {
    int fd,sz;
    char buf[20] = {0};
    fd = open("imput.txt",O_RDONLY);
    if(fd<0) {
        perror("ERROR:");
        exit(1);
    }
    sz = read(fd,buf,10);
    printf("\ncall 1 called read fd=%d and %d bytes read\n",fd,sz);
    buf[sz] = '\0';
    printf("\n read bytes are as follows:\n<%s>\n",buf);
    printf("\n Note next set of bytes read from the file ae continuous\n");
    sz=read(fd,buf,11);
    printf("\ncall 2 called read fd=%d and %d bytes read\n",fd,sz);
    buf[sz] = '\0';
     printf("\n read bytes are as follows:\n<%s>\n",buf);
     sz = read(fd,buf,10);
    printf("\ncall 3 called read fd=%d and %d bytes read\n",fd,sz);
    if(sz==0) {
        printf("EOF reached");
    }
}
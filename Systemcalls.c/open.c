#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
void main() {
    int fd;
    fd = open("startup",O_RDONLY);
    if(fd=-1) {
        printf("\n open() was failed - errno = (%d)\n",errno);
        perror("ERROR:");
    }else{
        printf("\n open() system call successfully executed,the file descrptor of opened file is %d\n",fd);
    }

}
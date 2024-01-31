#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
void main() {
    int fd,i;
    fd = open("input.txt",O_RDWR);
    if(fd<0) {
        sleep(5);
        fd = open("input.txt",O_RDWR|O_CREAT,666);
        if(fd>0) {
            printf("\nProgram1 created input.txt\n");
            close(fd);
        }
    }
}
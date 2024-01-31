#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<stdlib.h>
void main() {
    int sz;
    int buf[100];
    strcpy(buf,"This is an example of O_APPEND:\n");
    //O_TRUNC: write in file from beginning , discarding old contents
    //O_APPEND: write the contents of file from end of current file
    //TWO ABOVE TECHNIQUES ARE MODES TO WRITE ON A FILE
    int fd = open("input.txt",O_WRONLY | O_APPEND);
    if(fd<0) {
        perror("ERROR:");
        exit(1);
    } 
    printf("\nLength of buf is:%d\n",(int)strlen(buf));
    sz=write(fd,buf,strlen(buf));
    printf("\n write() returned %d\n",sz);
    close(fd);
}
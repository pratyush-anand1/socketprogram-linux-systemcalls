#include<unistd.h>
#include<string.h>
void main() {
    size_t len;
    char buf[100];
    int msg_len=0;
    strncpy(buf,"This is writing to screen using write() system call instead of printf() lib func call\n",99);
    msg_len = strlen(buf);
    len = write(1,buf,msg_len);
    //1-> FILE DESCRIPTOR
    //buf has the content that needs to be written
    //msg_len  is number of bytes of buf to be printed on screen 
}
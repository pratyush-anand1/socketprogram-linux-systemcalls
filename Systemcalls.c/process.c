#include<stdio.h>
#include<unistd.h>
void main() {
    printf("\nProcess ID of caller is %d\n",getpid());//MIGHT KEEP CHANGING
    printf("\nProcess ID of parent process is %d\n",getppid());//ALWAYS CONSTANT    
    sleep(5);
}
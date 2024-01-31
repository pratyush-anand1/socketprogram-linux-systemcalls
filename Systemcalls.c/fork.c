#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int main() {
  pid_t id;
  printf("\nParent Process:Executed by parent process before fork() execution pid = (%d)\n",getpid());
  id = fork();
  if(id<0) {
    printf("\nfork failed\n");
    exit(-1);
  }
  if(id>0) {
    printf("\nParent Process:I have created child process with ID = (%d)\n",id);
  } else {
    printf("\n I am child process with id value (%d)\n",id);
    printf("\nchild process id is (%d)\n",getpid());
    printf("\nthe creator of child process has id (%d)\n",getppid());
  }
}
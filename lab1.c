#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
    pid_t pid;
    pid=fork();
    if(pid<0){
        printf("error");
    }
    if(pid==0){
        printf("child having id is %d\n",getpid());
        execlp("/bin/ls","ls",NULL);
        printf("my parent id %d\n",getppid());
    }
    if(pid>0){
        printf("i am parent having id %d",getpid());
        printf("child id %d",pid);
    }
    return 0;
}

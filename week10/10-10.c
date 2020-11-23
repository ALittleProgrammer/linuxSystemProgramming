#include "ch10.h"

int main(){
    pid_t pid[2];
    pid_t mpid=getpid();
    int status[2];
    int i = 0;
    for (; i < 2; i++)
    {
        if(getpid()==mpid){
            pid[i]=fork();
        }
    }
    if(pid[0]==0){
        printf("child 1 : pid =%d ppid = %d\n",getpid(),getppid());
        sleep(1);
        exit(11);
    }
    if(pid[1]==0){
        printf("child 2 : pid =%d ppid = %d\n",getpid(),getppid());
         sleep(1);
        exit(22);
    }
    if (mpid==getpid())
    {
        waitpid(pid[0],&status[0],0);
        waitpid(pid[1],&status[1],0);
        printf("Parent: child 1 : pid = %d exitStatus=%d\n",pid[0],WEXITSTATUS(status[0]));
        printf("Parent: child 2 : pid = %d exitStatus=%d\n",pid[1],WEXITSTATUS(status[1]));
    }
}
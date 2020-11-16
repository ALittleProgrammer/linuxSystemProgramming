#include "ch09.h"

int main(){
    FILE* fd_out=fopen("./out.dat","w");
    pid_t pid[2];
    int fd[2];
    pid_t mPid=getpid();
    int i=0;
    int global=1;
    pipe(fd);
    write(fd[1],&global,1);
    for(i=0;i<2;i++){
        if(mPid==getpid()){
            pid[i]=fork();
        }
    }
    pid_t mmpid=getpid();
    for(i=0;i<2;i++){
        if(pid[0]==0&&mmpid==getpid()){
            fork();
        }
    }
    while(read(fd[0],&global,1)>0)
    {
        fprintf(fd_out,"%d : %d\n",getpid(),global);
        global++;
        write(fd[1],&global,1);
        break;
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    sleep(1);
}
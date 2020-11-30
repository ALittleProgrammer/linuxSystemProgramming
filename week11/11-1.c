#include "ch11.h"

int main(){
    pid_t pid1,pid2;
    pid1=fork();
    if(pid1<0){
        perror("fork pid failed!\n");
        exit(-1);
    }else if(pid1==0){
        printf("child1 :pid =%d,ppid=%d\n",getpid(),getppid());
        while(1);
        exit(0);
    }else{
        pid2=fork();
        if(pid2<0){
            perror("fork pid faild!\n");
            exit(-1);
        }else if(pid2==0){
            printf("child2 :pid =%d,ppid=%d\n",getpid(),getppid());
            while(1);
            exit(0);
        }
        else{
            int r1,r2,s1,s2;
            r1=wait(&s1);
            r2=wait(&s2);
            if(r1==pid1){
                printf("first exit: child1 exit,pid=%d, code = %d\n",r1,WEXITSTATUS(s1));
                if(WIFSIGNALED(s1)){
                    printf("child1 signal code = %d\n",WTERMSIG(s1));
                    psignal(WTERMSIG(s1),"child1 exit : ");
                }else if(WIFSTOPPED(s1)){
                    printf("child1 stop code = %d \n",WSTOPSIG(s1));
                }
            }
            if(r2==pid2){
                printf("second exit: child2 exit,pid=%d, code = %d\n",r2,WEXITSTATUS(s2));
                if(WIFSIGNALED(s2)){
                    printf("child2 signal code = %d\n",WTERMSIG(s1));
                    psignal(WTERMSIG(s1),"child2 exit : ");
                }else if(WIFSTOPPED(s2)){
                    printf("child2 stop code = %d \n",WSTOPSIG(s1));
                }
            }
            if(r1==pid2){
                printf("first exit: child2 exit,pid=%d, code = %d\n",r1,WEXITSTATUS(12));
                if(WIFSIGNALED(s1)){
                    printf("child2 signal code = %d\n",WTERMSIG(s1));
                    psignal(WTERMSIG(s1),"child2 exit : ");
                }else if(WIFSTOPPED(s1)){
                    printf("child2 stop code = %d \n",WSTOPSIG(s1));
                }
            }
            if(r2==pid1){
                printf("second exit: child1 exit,pid=%d, code = %d\n",r2,WEXITSTATUS(s2));
                if(WIFSIGNALED(s2)){
                    printf("child1 signal code = %d\n",WTERMSIG(s1));
                    psignal(WTERMSIG(s1),"child1 exit : ");
                }else if(WIFSTOPPED(s2)){
                    printf("child1 stop code = %d \n",WSTOPSIG(s1));
                }
            }
            return 0;
        }
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dlfcn.h>
#include <setjmp.h>
#include <wait.h>
#include <errno.h>
#define InFile "./in.txt"
#define OutFile "out.txt"
#define MODE 664

void pr_exit(int status,pid_t pid){
    int sig;
    if(WIFEXITED(status)){
        printf("process %d normal termination, exit status = %d\n",pid,WEXITSTATUS(status));
    }else if(WIFSIGNALED(status)){
        sig=WTERMSIG(status);
        printf("process %d abnormal termination, signal number = %d%s:\n",pid,sig,
#ifdef WCOREDUMP
    WCOREDUMP(status)?"(core file generated)":"");
#else
    "");
#endif
    psignal(sig,"");
    }
    else if(WIFSTOPPED(status)){
        sig=WSTOPSIG(status);
        printf("process %d stopped,signal number = %d:",pid,sig);
        psignal(sig,"");
    }
}
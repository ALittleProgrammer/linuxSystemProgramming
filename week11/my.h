/**
 * @Author: Peng JianKun 
 * @Date: 2020-11-30 16:27:08 
 * @Last Modified by: Peng JianKun
 * @Last Modified time: 2020-11-30 17:14:16
 **/
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
#include <string.h>
#include <time.h>
#define InFile "./in.txt"
#define OutFile "log.dat"
#define MODE O_RDWR|O_CREAT|O_TRUNC

void pr_info(int fd,int pid , int ppid,char* name){
    char buf[BUFSIZ];
    time_t timep;
    time (&timep);
    memset(buf,'\0',sizeof(buf));
    sprintf(buf,"%s : pid = %d , ppid = %d , time = %s \n",name,pid,ppid,ctime(&timep));
    write(fd,buf,strlen(buf));
//    printf("%d\n",tell(fd));
    printf("%s",buf);
    close(fd);
}

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
#include "ch09.h"

int main(){
    int fd_in,fd_out;
    char buf[1024];
    pid_t pid;
    memset(buf,0,1024);
    fd_in=open(InFile,O_RDONLY);
    if(fd_in<0){
        fprintf(stderr,"failed to open %s,reason(%s)\n",InFile,strerror(errno));
        exit(0);
    }
    fd_out=open(OutFile,O_WRONLY|O_CREAT|O_TRUNC,MODE);
    if(fd_out<0){
        fprintf(stderr,"failed to open %s,reason(%s)\n",OutFile,strerror(errno));
        return 1;
    }
    pid=fork();
    if(pid<0){
        fprintf(stderr,"failed tp dork ,reason(%s)\n",strerror(errno));
        return 1;
    }
    while (read(fd_in,buf,2)>0){
        printf("%d: %s\n",getpid(),buf);
        sprintf(fd_out,"%d: Hello Word!\n",getpid());
        memset(buf,0,1024);
    }
    close(fd_in);
    close(fd_out);
    return 0;
}
#include "ch10.h"
extern char**environ;
int main(int argc,char*argv[]){
    int i = 0;
    char**env=environ;
    printf("./test pid=%d ppid=%d\n",getpid(),getppid());
    for (; i < argc; i++)
    {
        printf("%s ",argv[i]);
    }
    printf("\n");
    return 99;
}
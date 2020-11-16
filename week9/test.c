#include "ch09.h"
extern char**environ;
int main(int argc,char*argv[]){
    int i = 0;
    char**env=environ;
    for (; i < argc; i++)
    {
        printf("%s ",argv[i]);
    }
    printf("\n");
    while (*env)
    {
        printf("%s\n",*env);
        env++;
    }
    exit(EXIT_SUCCESS);
}
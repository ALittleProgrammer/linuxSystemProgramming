#include "ch09.h"
int main(){
    char*env_init[]={"USER=std","PATH=/temp",NULL};
    if(execle("./test","./test","hello"," world!",NULL,env_init)==-1){
        perror("execle!");
        exit(EXIT_FAILURE);
    }
    puts("Never get here!\n");
    exit(EXIT_FAILURE);
}
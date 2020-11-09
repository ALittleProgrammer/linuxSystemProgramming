#include "ch08.h"

int i=0;
int main(){
    doF();
}

void doF(){
    i++;
    printf("this is %d\n",i);
    doF();
}
#include "ch08.h"

int main()
{
    int *pt=NULL;
    int i=0;
    pt=malloc(1024*1024);
    i++;
    while (pt)
    {
        printf("malloc %d MB\n",i);
        pt=malloc(1024*1024);
        i++;
    }
    printf("max malloc is %d MB",i);
    return 0;
}
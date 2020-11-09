#include "./ch08.h"

void dynamic_lib_fun_call(){
    printf("----this is dybamicLibFunCal----\n");
}

int mycompar(const void * a, const void * b){
    return ( *(int*)a - *(int*)b );
}

void mysort(int nums[],int sum){
    qsort(nums,sum,sizeof(int),&mycompar);
    // int i;
    // for (i = 0; i < sum; i++)
    // {
    //     printf("nums[%d] is %d\n",i,nums[i]);
    // }
}

void myRand(int nums[],int sum){
    srand((unsigned) time(NULL));
    int i;
    for(i=0;i<sum;i++){
        
    }
}
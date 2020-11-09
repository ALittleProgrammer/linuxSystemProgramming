
/*
 * @Author: Peng JianKun 
 * @Date: 2020-11-09 10:51:21 
 * @Last Modified by: Peng JianKun
 * @Last Modified time: 2020-11-09 10:51:42
 */

#include "ch08.h"

int main(){
    int nums[]={3,5,2,6,4};
    int sum=5;
    void *fpt=dlopen("./libdlib.so",RTLD_NOW);
    if(!fpt){
        printf("load libdlib.so fail!\n");
        exit(1);
    }
    void (*func)(void)=dlsym(fpt,"dynamic_lib_fun_call");
    void (*mysort)(int[],int sum)=dlsym(fpt,"mysort");
    if(!func||!mysort)
    {
        printf("function Failded\n");
        exit(1);
    }
    func();
    int i;
    for (i = 0; i < sum; i++)
    {
        printf("nums[%d] is %d\n",i,nums[i]);
    }
    mysort(nums,sum);
    printf("\n----After sort----\n\n");
    for (i = 0; i < sum; i++)
    {
        printf("nums[%d] is %d\n",i,nums[i]);
    }
    dlclose(fpt);
    return 0;
}
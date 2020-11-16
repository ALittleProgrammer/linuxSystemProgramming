#include "ch09.h"

int main(){
    char buf[1024]="this is data";
    int i=10;
    pid_t pid;
    pid=vfork();
    if(pid>0){
        printf("child: buf is \"%s\" i = %d\n",buf,i);
        i++;
        memcpy(buf,"you have be hacked!",1024);
        _exit(0);
    }else if(pid==0){
        printf("parent: buf is \"%s\" i = %d\n",buf,i);
        _exit(0);
    }
}
// #include "ch09.h"
// int g_int=1;
// static int st=0;
// int main(){
//     pid_t pid;
//     int l_int=99;
//     int *pt=malloc(sizeof(int));
//     char *string="test string!";
//     *pt=9999;
//     printf("%d:------Before Fork-------",getpid());
//     pid=fork();
//     if(pid<0){
//         fprintf(stderr,"failed to fork.Reason(%s)\n",strerror(errno));
//         exit(-1);
//     }else if(pid==0){
//         printf("child : pid = %d, ppid = %d return from fork()=%d\n",getpid(),getppid(),pid);
//         printf("child : init g=%d,l=%d,*pt=%d,st=%d\n",g_int,l_int,*pt,st);
//         g_int++;
//         l_int++;
//         (*pt)++;
//         st++;
//         printf("child : init g=%d,l=%d,*pt=%d\n",g_int,l_int,*pt);
//         printf("address of l_int = 0x%x ,g = 0x%x , pt = 0x%x\n",&l_int,&g_int,pt);
//         printf("child : string = %s\n",string);
//         exit(0);
//     }else{
//         sleep(2);
//         printf("parent : pid = %d, ppid = %d return from fork()=%d\n",getpid(),getppid(),pid);
//         printf("parent : init g=%d,l=%d,*pt=%d,st=%d\n",g_int,l_int,*pt,st);
//         g_int++;
//         l_int++;
//         (*pt)++;
//         printf("parent : init g=%d,l=%d,*pt=%d\n",g_int,l_int,*pt);
//         printf("address of l_int = 0x%x ,g = 0x%x , pt = 0x%x\n",&l_int,&g_int,pt);
//         printf("parent : string = %s\n",string);
//         exit(0);
//     }
// }
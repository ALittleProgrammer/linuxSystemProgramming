/*
 * @Author: Peng JianKun 
 * @Date: 2020-11-30 16:27:21 
 * @Last Modified by: Peng JianKun
 * @Last Modified time: 2020-11-30 17:15:06
 */

#include "my.h"

int main()
{
    pid_t pid1;
    pid1 = fork();
    int fd;
    fd = open(OutFile,MODE);
    if (fd < 0)
    {
        printf("can't open file!\n");
    }
    else
    {
        if (pid1 < 0)
        {
            perror("fork pid failed!\n");
            exit(-1);
        }
        else if (pid1 == 0)
        {

            //子进程1
            pid_t pid11;
            pid11 = fork();
            if (pid11 < 0)
            {
                printf("fork failed!\n");
            }
            else if (pid11 == 0)
            {
                //1进程的子进程11
                pr_info(fd, getpid(), getppid(), "child11");
                exit(0);
            }
            else
            {
                int s;
                waitpid(pid11, &s, 0);
                pr_info(fd, getpid(), getppid(), "child1");
                exit(0);
            }
        }
        else
        {
            int pid2;
            pid2 = fork();
            if (pid2 < 0)
            {
                perror("fork pid faild!\n");
                exit(-1);
            }
            else if (pid2 == 0)
            {

                //子进程2
                pid_t pid22;
                pid22=fork();
                if (pid22 < 0)
                {
                    printf("fork failed!\n");
                }
                else if (pid22 == 0)
                {
                    //2进程的子进程22
                    pr_info(fd, getpid(), getppid(), "child22");
                    exit(0);
                }
                else
                {
                    int s;
                    waitpid(pid22, &s, 0);
                    pr_info(fd, getpid(), getppid(), "child2");
                    exit(0);
                }
            }
            else
            {
                //父进程
                int s1, s2;
                waitpid(pid1, &s1, 0);
                waitpid(pid2, &s2, 0);
                //printf("1 = %d , 2 = %d \n",WEXITSTATUS(s1),WEXITSTATUS(s2));
                char buf[BUFSIZ];
                lseek(fd,0,SEEK_END);
                while ((read(fd,buf,sizeof(buf))) > 0)
                {
                    printf("%s", buf);
                }
                pr_info(fd, getpid(), getppid(), "parent");
            }
        }
    }
}
#include "ch04.h"
char buf1[]="abcdefghij";
char buf2[]="0123456789";
int main(void)
{
	int fd;
	if((fd=open("file.hole.2",O_WRONLY|O_CREAT|O_APPEND,0644))<0)
	{
			printf("Create error!\n");
			exit(1);
	}
	if((write(fd,buf1,sizeof(buf1)))!=sizeof(buf1)){                                                                            printf("write error!");
		printf("write error!\n");
		exit(1);
	}
	if((lseek(fd,40,SEEK_SET))==-1){
			printf("lseek error!\n");
			exit(1);
	}
	if((write(fd,buf2,sizeof(buf2)))!=sizeof(buf2)){
		printf("write error!\n");
		exit(1);
	}
	return 0;
}

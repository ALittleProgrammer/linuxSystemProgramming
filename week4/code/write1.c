#include "ch04.h"
#include <time.h>

int main(){
	int n,i,fd;
	char buf;
	fd=open("./test.dat",O_CREAT|O_WRONLY,0644);
	if(fd==-1){
		printf("open faild\n");
	}
	for(i=0;i<2;i++)
	{
		srand(time(0));
		n=rand()%26;
		buf=(char)('a'+n);
		printf("fd is %d",fd);
		printf("write1:%c\n",buf);
		write(fd,&buf,1);
		lseek(fd,10,SEEK_SET);
		sleep(20);
	}
	close(fd);
}

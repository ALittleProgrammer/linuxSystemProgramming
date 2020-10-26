#include "ch04.h"
int main(){
	int d1,d2;
	char buf[5];
	memset(buf,0,5);
	d1=open("file.hole",O_RDONLY);
	d2=open("file.hole",O_RDONLY);
	int d3=dup(d1);
	printf("d1=%d,d2=%d,d3=%d\n",d1,d2,d3);
	lseek(d1,5,SEEK_SET);
	read(d2,buf,1);
	printf("from d2 buf is %s\n",buf);
	read(d1,buf,1);
	printf("from d1 buf is %s\n",buf);
	read(d3,buf,1);
	printf("from d3 buf is %s\n",buf);
	close(d1);
	close(d2);
	close(d3);
	return 0;
}


#include "ch02.h"

int main(){
	FILE *fp;
	int fd;
	fd=open("./test2",O_RDWR);
	fp=fdopen(fd,"w+");
	fprintf(fp,"test data %s]n","hello word");
	fclose(fp);
	return 0;
}

#include "ch02.h"

int main(int argc,char*argv[]){
	FILE *fp;
	int ret;
	if((fp=fopen("./test1.txt","w"))==NULL)
		perror("open failed!");
	for(int i=1;i<argc;i++){
		printf("Content is %s.The size of stream is %ld bytes.\n",argv[i],sizeof(argv[i]));
		ret = fwrite(argv[i],4,sizeof(argv[i])/4,fp);
		printf("Actual writing number of item is %d\n",ret);
	}
	fclose(fp);
	return 0;
}

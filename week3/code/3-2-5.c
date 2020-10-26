#include "ch02.h"

int main(int argc,char*argv[]){
	FILE *fp;
	int ret;
	if((fp=fopen("./test1.txt","w"))==NULL)
		perror("open failed!");
	for(int i=1;i<argc;i++){
		printf("Content is %s.The size of stream is %ld bytes.\n",argv[i],strlen(argv[i]));
		ret = fwrite(argv[i],1,strlen(argv[i]),fp); //不能用sizeof(),sizeof指针的结果都是8,即指针长度
		printf("Actual writing number of item is %d\n",ret);
	}
	fclose(fp);
	return 0;
}

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init();
void readOne(FILE* fd,int num);
char buf[BUFSIZ];

struct SINT{
	int num;
};

int main(int argc,char*argv[]){
	if(argc<2){
		printf("<cmd> num(0-3)\n");
	}else{
		init();
		FILE* fp=fopen("data.txt","rb");
		memset(buf,'\0',sizeof(buf));
		readOne(fp,(*argv[1])-'0');
		printf("%s. is %s\n",argv[1],buf);
		int i=0;
		fclose(fp);
	}
}

//创建data.txt用于测试
void init(){
	FILE* fp=fopen("data.txt","wb");
	if(fp==NULL){
		printf("fail to open data.txt\n");
		return;
	}
	printf("create file 'data.txt' sucess!\n");
	int sum=3;
	char c1[]="axcsdf";
	char c2[]="acswieos";
	char c3[]="12345";
	int n1=sizeof(c1);
	int n2=sizeof(c2);
	int n3=sizeof(c3);
	printf("datas:\n");
	printf("1. %s\n",c1);
	printf("2. %s\n",c2);
	printf("3. %s\n",c3);
	//printf("%d\n",sizeof(sum));
	fwrite(&sum,sizeof(sum),1,fp);
	fwrite(&n1,sizeof(n1),1,fp);
	fwrite(&n2,sizeof(n2),1,fp);
	fwrite(&n3,sizeof(n3),1,fp);
	fwrite(&c1,sizeof(c1),1,fp);
	fwrite(&c2,sizeof(c2),1,fp);
	fwrite(&c3,sizeof(c3),1,fp);
	fflush(fp);
	fclose(fp);
}

//读取函数
void readOne(FILE* fp,int num){
	printf("\nstart reading...\n");
	int sum=0;
	int offset=0;
	int len=0;
	fread(&sum,sizeof(sum),1,fp);
	if(sum<num){
		printf("num is too long\n");
		return;
	}
	int temp=0;
	for(int i=1;i<num;i++){
		fread(&temp,sizeof(temp),1,fp);
		//printf("temp is %d\n",temp);
		offset+=temp;
	}
	fread(&len,sizeof(len),1,fp);
	//printf("len is %d\n",len);
	offset=(sum+1)*4+offset;
	//printf("offset is %d\n",offset);
	rewind(fp);
	fseek(fp,offset,SEEK_SET);
	fread(buf,1,len,fp);
	//int size=fread(buf,1,len,fp);
	//printf("read size is %d\n",size);
	//printf("error is %d\n",ferror(fp));
}

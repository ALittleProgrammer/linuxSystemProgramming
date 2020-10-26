#include <stdio.h>
#include <string.h>


int main(){
	char buf1[10];
	char buf2[10];
	memset(buf1,'\0',sizeof(buf1));
	memset(buf2,'\0',sizeof(buf2));
	printf("buf2 size is %d\nplease input string: ",sizeof(buf2));
	gets(buf2);
	printf("write to buf2...\n");
	printf("buf1 is %s , buf2 is %s\n",buf1,buf2);
	if(buf1[0]!='\0'){
		printf("\n\nBOOM!!!!\n");
		printf("we don't write in buf1 ,but buf1 has value! And buf2 size is more than 10\n\n\n");
	}else{
		printf("\n\nnothing happened!\n");
	}
	return 0;
}

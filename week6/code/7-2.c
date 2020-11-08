#include "ch06.h"

int main(int argc,char*argv[]){
	if(argc!=3){
		printf("args error!\n");
		return 0;
	}
	printf("%d\n",atoi(argv[1])+atoi(argv[2]));
	return 0;
}

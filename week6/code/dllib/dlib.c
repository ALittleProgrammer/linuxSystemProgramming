#include "../ch06.h"

void dynamic_lib_call(void)
{
	printf("Dynamic lib is called!\n");
}

int add(int a,int b){
	return a+b;
}

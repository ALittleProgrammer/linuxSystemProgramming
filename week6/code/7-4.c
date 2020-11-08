#include "ch06.h"

static void __attribute__ ((destructor)) endMain(){
	printf("----this is EndMain----\n");
}

static void callback1(void)
{
	printf("----this is Callback1----\n");
}
static void callback2(void)
{
	printf("----this is Callback2----\n");
}
static void callback3(void)
{
	printf("----this is Callback3----\n");
}
int main(void){
	atexit(callback1);
	atexit(callback2);
	atexit(callback3);
	printf("----Main End----\n");
	exit(0);
}

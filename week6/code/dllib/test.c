#include "../ch06.h"

//extern void dynamic_lib_call(void);

int main(int argv,char*argc[]){
	if(argv!=3){
		printf("args error!\n");
		exit(-1);
	}
	void *dlib=dlopen("./libdlib.so",RTLD_NOW);
	if(!dlib){
		printf("dlopen failed!\n");
		exit(-1);
	}
	void(*dfunc)(void)=dlsym(dlib,"dynamic_lib_call");
	int(*addFunc)(int,int)=dlsym(dlib,"add");
	if(!dfunc)
	{
		printf("dfunc is failed to load!\n");
		exit(-1);
	}
	if(!addFunc){
		printf("addFunc is failed to load!\n");
		exit(-1);
	}
	dfunc();
	printf("%s + %s = %d\n",argc[1],argc[2],addFunc(atoi(argc[1]),atoi(argc[2])));
	dlclose(dlib);
	//dynamic_lib_call();
	return 0;
}


/*
 * @Author: Peng JianKun 
 * @Date: 2020-11-08 22:47:30 
 * @Last Modified by: Peng JianKun
 * @Last Modified time: 2020-11-08 23:05:55
 */

#include "ch06.h"

static void set_env_string(void){
	// char test_env[]="test_env=test";
	if(setenv("test_env","Test",0)!=0){
		printf("---Putenv is failed!---\n");
	}
	printf("1.The test_env = %s\n",getenv("test_env"));
}

static void show_env_string()
{
	printf("2.The test_env =%s\n",getenv("test_env"));
}

int main(){
	set_env_string();
	show_env_string();
	return 0;
}

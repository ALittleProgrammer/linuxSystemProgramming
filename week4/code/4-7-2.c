#include "ch04.h"

int main()
{
	int d1=open("hole.info",O_CREAT|O_TRUNC);
	char buf[1]="c";
	while(1){
		write(d1,buf,1);
		sleep(1);
	}
}

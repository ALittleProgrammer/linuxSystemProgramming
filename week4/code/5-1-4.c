#include "ch04.h"

char outbuf[BUFSIZ]; 
int main(void) 
{ 
	printf("Hello word.");
	//fflush(stdout);
	fclose(stdout);
	while(1);
	return 0; 
}

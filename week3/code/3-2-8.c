#include "ch02.h"

int main(){
	FILE *fp;
	fdopen(1,"w+");
	fprintf(fp,"test data %s","hello word");
	fclose(fp);
	return 0;
}

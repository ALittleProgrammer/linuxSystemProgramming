#include "ch06.h"

static void __attribute__ ((constructor)) before_main()
{
	printf("----------Before Main----------\n");
}

static void __attribute__ ((destructor)) end_main()
{
	printf("----------End Main----------\n");
}

int main()
{
	printf("----------Main Function----------\n");
	return 0;
}

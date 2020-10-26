#include <limits.h>
#include <stdio.h>
#include <float.h>

int main(){
	int n1=1;
	float n2=1;
	double n3=1;
	printf("std max int is %d\n",INT_MAX);
	printf("std min int is %d\n",INT_MIN);
	/*
	while(1){
		temp1=n1+1;
		if(temp<0){
			printf("my max int is %d\n",n1);
			printf("my min int is %d\n",temp1);
			break;
		}
		n1++;
	}*/
	printf("my max int is %d\n",(1<<(sizeof(int)*8-1))-1);
	printf("my min int is %d\n\n",1<<(sizeof(int)*8-1));

	char *p=(char*)&n2;
	 
	*p=0xff;
	*(p+1)=0xff;
	*(p+2)=0x7f;
	*(p+3)=0x7f;
	printf("std max float is %e\n",FLT_MAX);
	printf("std min float is %e\n",FLT_MIN);
	printf("my max float is %e\n",n2);

	*p=0x01;
	*(p+1)=0x00;
	*(p+2)=0x80;
	*(p+3)=0x00;

	printf("my min float is %e\n\n",n2); 

	printf("std max double is %e\n",DBL_MAX);
	printf("std min double is %e\n",DBL_MIN);
	
	p=(char*)&n3;
	*p=0xff;
	*(p+1)=0xff;
	*(p+2)=0xff;
	*(p+3)=0xff;
	*(p+4)=0xff;
	*(p+5)=0xff;
	*(p+6)=0xef;
	*(p+7)=0x7f;
	printf("my max double is %e\n",n3);

	p=(char*)&n3;
	*p=0x01;
	*(p+1)=0x00;
	*(p+2)=0x00;
	*(p+3)=0x00;
	*(p+4)=0x00;
	*(p+5)=0x00;
	*(p+6)=0x10;
	*(p+7)=0x00;
	printf("my min double is %e\n",n3);
	//while(1){

	//}
}

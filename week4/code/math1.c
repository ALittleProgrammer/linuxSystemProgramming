#include <stdio.h>

int action(int start,int max);

int main(){
	int flag=0;
	int start=0;
	int max=1000000;
	while(!action(start,max)){
		start=max;
		max=max*2;
		if(start<0||max<0){
			break;
		}
	}
	return 0;
}

int action(int start,int max){
	int flag=0;
	int i=start,j=start,k=start;
	printf("正在尝试%d -- %d\n",start,max);
	 for (;i<max;i++){
		         for (;j<max;j++){
					             for(;k<max;k++)
									             {
													                 if(i*1.0/(j+k)+j*1.0/(i+k)+k*1.0/(i+j)==4){
																		                     printf("i is %d, j is %d, k is %d\n",i,j,k);
																							                     flag=1;
																												                 }
																	             }
								         }
				     }
	 if(!flag){
		 printf("%d -- %d 中无解\n",start,max);
	 }
	 return flag;
}

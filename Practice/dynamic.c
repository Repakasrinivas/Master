#include<stdio.h>
#include<stdlib.h>

int dynamic_memory(){
	int *ptr = malloc(sizeof(int));
	*ptr = 10;
	return *ptr;
}
int static_memory(){
	int a = 20;
	return a;
}

void normal_memory(){
	int a = 40;
	a++;
}

int main(void){
	int a,b;
	a=dynamic_memory();
	b=static_memory();
	normal_memory();
	printf("%d %d\n",a,b);
	return 0;

}

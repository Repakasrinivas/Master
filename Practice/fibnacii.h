#include<stdlib.h>
#include<stdio.h>

int* fibnacii(int* arr,int value){
	int start = 0;
	int n = 1;
	int temp = 0;
	int *result = (int*)malloc(sizeof(int));
	for(int iter=0;iter<value;iter++){
		temp = start;
		start = n;
	       	n = start+temp;
		(*result)++;	
		arr[iter] = temp;
	}
	return result;
}	

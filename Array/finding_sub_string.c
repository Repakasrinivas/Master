#include<stdio.h>
#include<stdlib.h>
#define SIZE 20

int main(void){
	int *arr = malloc(sizeof(int)*SIZE);
	int *arr1 = malloc(sizeof(int)*SIZE);
	int size;
	int sub_size;

	printf("enter size of array : ");
	scanf("%d",&size);
	printf("enter elements of the array : ");
	for(int iter=0;iter<size;iter++){
		scanf("%d",&arr[iter]);
	}
	printf("enter size of substring : ");
	scanf("%d",&sub_size);
	printf("enter elements of the sub array : ");
	for(int iter=0;iter<sub_size;iter++){
		scanf("%d",&arr1[iter]);
	}
	if(sub_size > size)
		return 0;
	for(int iter1 = 0; iter1 < size; iter1++){
			if(arr1[0] == arr[iter1]){
				int count = 1;
				for(int iter3 = 1; iter3 < sub_size; iter3++){
					if(arr1[iter3] == arr[iter1+iter3]){
						count++;		
					}
				}
				if(count == sub_size){
					printf("sub array is found \n");
					return 0;
				}
			}
	}
	printf("sub string is not found\n");
	return 0;
}

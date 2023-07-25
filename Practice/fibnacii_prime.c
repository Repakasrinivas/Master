#include</home/srinivasr/Desktop/Practice/fibnacii.h>
#include</home/srinivasr/Desktop/Practice/prime.h>
#define SIZE 15

int main(void){
	int* size;
	int length;
	int *arr = malloc(sizeof(int)*SIZE);
	printf("enter number of digits needed for fibnacii : ");
	scanf("%d",&length);
	size = fibnacii(arr,length);
	for(int iter=0;iter<(*size);iter++)
		printf("%d ",arr[iter]);
	printf("\n");
	for(int iter=3;iter<(*size);iter++){
		if(is_prime(arr[iter]))
			printf("%d is prime\n",arr[iter]);
	}
	return 0;
}

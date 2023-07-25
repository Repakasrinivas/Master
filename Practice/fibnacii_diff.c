#include</home/srinivasr/Desktop/Practice/fibnacii.h>
#include</home/srinivasr/Desktop/Practice/diff.h>
#define SIZE 15

int main(void){
        int* size;
        int length;
	int diff;
        int *arr = malloc(sizeof(int)*SIZE);
        printf("enter number of digits needed for fibnacii : ");
        scanf("%d",&length);
	printf("enter the difference to be caluclated :");
	scanf("%d",&diff);
        size = fibnacii(arr,length);
        for(int iter=0;iter<(*size);iter++)
                printf("%d ",arr[iter]);
        printf("\n");
        difference(arr,diff,(*size));
        return 0;
}


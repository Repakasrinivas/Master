#include<stdio.h>
#include<stdlib.h>

void free_ptr(int **ptr){
	free(*ptr);
	*ptr = NULL;
}

int main()
{
	int *ml = malloc(sizeof(int));
	*ml = 13;
	free_ptr(&ml);
	printf("%d\n",*ml);
	return 0;
}


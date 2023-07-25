void difference(int* arr, int value, int size){
	for(int iter1 = 0; iter1<size; iter1++)	{
		for(int iter2 = iter1; iter2 < size; iter2++){
			if((arr[iter2]-arr[iter1]) == value)
				printf("%d and %d\n",arr[iter1],arr[iter2]);
		}
	}
}

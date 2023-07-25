#include<stdio.h>

union example{
	int var;
	char ptr[sizeof(int)];
}variable;


int main(){
	variable.var = 0x12345678;
       printf("%X",(char)(variable.ptr[1]));	
}


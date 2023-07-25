#include<stdio.h>
#define SWAP(x) (x&0xFF00)|((x&0x0F)<<4)|((x&0xF0)>>4)

int main(){
	int x = 0x1234;
	printf("%X\n",SWAP(x));
}

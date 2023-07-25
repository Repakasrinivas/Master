#include "Encryption.h"

int main(void){
	char *input_str = malloc(20*sizeof(char));
	int enc_data = 0;
	char *enc_str = malloc(20*sizeof(char));
	printf("enter an encrypted string: ");
	scanf("%s",input_str);
	
	string_decryptor(input_str, enc_str);
	printf("encrypted string is %s\n",enc_str);
	enc_data = number_decryptor(input_str);
	printf("encrypted data is %d\n",enc_data);
	free(enc_str);
	free(input_str);
}

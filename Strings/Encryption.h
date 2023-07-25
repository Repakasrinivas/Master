#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define VALIDATE_CHAR(ch) ((ch>='a')&&(ch<='z'))||((ch>='A')&&(ch<='Z'))
#define VALIDATE_NUMBER(ch) ((ch>='0')&&(ch<='9'))

void string_decryptor(char* input_str, char* enc_str ){
        int count = 0;
        for(int iter = 0; iter<strlen(input_str);iter++){
                if(VALIDATE_CHAR(*(input_str+iter))){
                        *(enc_str+count) = *(input_str+iter);
                        count++;
                }
        }
}

int number_decryptor(char* input_str){
	char *num_dec = malloc(20*sizeof(char));
	int count = 0;
	for(int iter = 0;iter<strlen(input_str);iter++){
		if(VALIDATE_NUMBER(*(input_str+iter))){
			*(num_dec+count) = *(input_str+iter);
			count++;
		}
	}
	return atoi(num_dec);
}

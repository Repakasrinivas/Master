#include <stdio.h>
#include <string.h>

int main() {
    char string[100] = "Hello";
    int i = 0, letters = 0, longest = 0;
	//printf("enter string : ");
	//scanf("%[ ]s",string);
start:

    for (; ((string[i] != ' ') && (string[i] != '\0')); i++) {
        letters++;  
    }

    if (letters >= longest)
        longest = letters;

    if (string[i] == ' ')  {
        letters = 0;
        i++;
        goto start;
    }

    printf("Highest alphabets length is : %d\n", longest);

    return 0;
}

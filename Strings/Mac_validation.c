#include<stdio.h>
#include<string.h>

#define CHECK(ch) (((ch>='a')&&(ch<='f'))||((ch>='A')&&(ch<='F'))||(ch>='0')&&(ch<='9'))?1:0
#define COL_CHECK(ch) (ch==':')?1:0
#define PRINTF() printf("entered wrong MAC address\n")

void main(void){
    char str[20];
    printf("enter any MAC address : ");
    scanf("%s",str);
    int flag = 0;
    if((strlen(str)) != 17){
        if(flag!=1)
            flag=1;
    }
    else{
        for(int i=0;str[i]!='\0';i++)
        {
            if((i == 2) || (i == 5) || (i == 8) || (i == 11) || (i == 14)){
                if(!(COL_CHECK(str[i])))
                    if(flag!=1)
                        flag=1;
            }
            else{
                if(!(CHECK(str[i])))
                    if(flag!=1)
                        flag=1;
            }
        }
    }
    if(flag==1)
        PRINTF();
    else
        printf("VALID MAC\n");
}



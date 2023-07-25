#include<stdio.h>
#include<string.h>

int reverse(char *str,int n,int start)
{
	int j=n-1;
	for(int i=start;i<(n/2);i++,j--)
	{
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		printf("in reverse %s\n",str);
	}
	return 0;
}

void rev_words(char *str)
{
	int start_pos=0,end_pos=0;
	for(end_pos=0;str[end_pos] != '\0';end_pos++)
	{
		if((str[end_pos] == ' ')||(str[end_pos+1] == '\0'))
		{
			reverse(str,end_pos,start_pos);
			end_pos = start_pos+1;
		}
	}
	printf("output = %s\n",str);
}

int main()
{
	char str[32];	
	printf("enter a string\n");
	scanf("%[^\n]s",str);
	void (*fptr)(char*) = rev_words;
	(*fptr)(str);	
	printf("output = %s\n",str);
	return 0;
}

#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<string.h>

typedef struct dob{
	int date;
	int month;
	int year;
}dob;

typedef struct list{
	char name[20];
	char mailid[40];
	dob date;
}list;


typedef struct data{
	char storage[8];
	list details;
	struct data *next;
}data;



void create_node_linked_list(data **head, char *input_data){
	data *new = (data*)malloc(sizeof(data));
	strcpy(new->storage,input_data);
	printf("enter the person name : ");
	scanf("%s",new->details.name);
	printf("enter the person mailid : ");
	scanf("%s",new->details.mailid);
	printf("enter date of birth : ");
	scanf("%d-%d-%d",&(new->details.date.date), &(new->details.date.month), &(new->details.date.year));
	if((*head) == NULL) {
		new->next = new;
		(*head) = new;

	}
	else {
		data *temp = *head;
		while(temp->next != *head){
			temp = temp->next;
		}
		temp->next = new;
		new->next = *head;
	}
}

void file_printing(data *head){
	FILE *fp;
	fp = fopen("data.txt","a+");
	data *temp = head;
	do{
		fprintf(fp,"%8s%20s%40s% 2d-%2d-%4d\n",temp->storage,temp->details.name,temp->details.mailid,temp->details.date.date,temp->details.date.month,temp->details.date.year);
		temp = temp->next;
	}while(temp != head);
	fclose(fp);
}

void print_node_linked_list(data *head){
	data *temp = head;
	do{
		printf("%s ",temp->storage);
		temp = temp->next;
	}while(temp != head);
	printf("\n");
}

int Input_data(char* input_node){
	printf("enter your id : ");
	scanf("%s",input_node);
	return 1;
}

int main(void){
	data *head = (data*)malloc(sizeof(data));
	head = NULL;
	static char input_node[8];

	char ch;
	do{
		if(Input_data(input_node));
		else printf("error in data reading\n");
		create_node_linked_list(&head,input_node);
		printf("Do you want to add the data Y/N :- ");
		__fpurge(stdin);
		ch = getc(stdin);
	}while((ch != 'N')&&(ch != 'n'));
	print_node_linked_list(head);
	file_printing(head);

}

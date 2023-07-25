#include<stdio.h>
#include<stdlib.h>

typedef struct data{
	char data;
	struct data *next;
}data;

typedef struct start{
	data data1;
	struct start *next;	
}start;


void create_node_linked_list(start *new){
	new = (start*)malloc(sizeof(start));
}


int main(void){
	start *new;
	start *head;
	create_node_linked_list(new);
	create_data_linked_list(head);
	return 0;
}

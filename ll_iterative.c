#include <stdio.h>
#include <stdlib.h>

struct list
{
	int number;
	struct list *next;
};

typedef struct list node;

node *head;
node *tail;

int main()
{
	void create(node *head);
	void print(node *head);
	head = (node*)malloc(sizeof(node));
	create(head);
	print(head);
	return 0;
}

void create(node *head)
{
	char choice;
	int i = 1;
	tail = head;
	while(i)
	{	
		printf("Enter the value of node number '%d'. Press 999 at the end\n", i);
		scanf("%d", &tail->number);
		if(tail->number == 999) 
		{
			tail->next = NULL;
			printf("Linked list created successfully\n");
			break;
		} 
		
		else
		{
			tail->next = (node*)malloc(sizeof(node));
			tail = tail->next;
		}
		i++;
	}		
}

void print(node *head)
{
	node *tail;
	tail = head;
	while(tail->next != NULL)
	{
		printf("%d-->", tail->number);
		tail = tail->next;
		if(tail->next == NULL)
			printf("%d\n", tail->number); 
	}
}

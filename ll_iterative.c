#include <stdio.h>
#include <stdlib.h>

void create();
void print();

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
	head = (node*)malloc(sizeof(node));
	create();
	print();
	return 0;
}

void create()
{
	node *temp;
	temp = head;
	int i = 1;
	while(i)
	{	
		printf("Enter the value of node number '%d'. Press 999 at the end\n", i);
		scanf("%d", &temp->number);
		if(temp->number == 999) 
		{
			temp->next = NULL;
			tail = temp;
			printf("Linked list created successfully\n");
			break;
		} 
		
		else
		{
			temp->next = (node*)malloc(sizeof(node));
			temp = temp->next;
		}
		i++;
	}		
}

void print()
{
	node *temp;
	temp = head;
	if(temp->next == NULL)
	{	
		printf("%d\nLinked list is empty\n", temp->number);
	}
	
	while(temp != tail)
	{
		printf("%d-->", temp->number);
		temp = temp->next;
	}
	printf("%d", temp->number);
	printf("\n");
}


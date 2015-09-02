#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int n;
	struct node *next;
}node;

node *tos1 = NULL;
node *tos2 = NULL;
/*void push(node **tos, int n);
void display_tos1(node *tos1);
void display_tos2(node *tos2);
void display(node *tos1, node *tos2);
int pop(node **tos);
void dequeue(node **tos1, node **tos2);
void enqueue(node **tos1, int n);
*/

void push(node **tos, int n)
{
	node *temp;
	temp = (node *) malloc(sizeof(node));
	temp->n = n;
	temp->next = *tos;
	*tos = temp;
}

void display_tos1(node *temp)
{
	while(temp != NULL)
	{
		printf("%d ", temp->n);
		temp = temp->next;
	}
}

void display_tos2(node *temp)
{
	if(temp != NULL)
	{
		display_tos2(temp->next);
		printf("%d ", temp->n);
	}
}

void display()
{
	printf("Queue:\n");
	display_tos1(tos1);
	display_tos2(tos2);
	printf("\n");
}

int pop(node **tos)
{
	int n = (*tos)->n;
	node *temp = (*tos)->next;
	free(*tos);
	*tos = temp;
	return(n);
}

void enqueue(int n)
{
	push(&tos1, n);
}

void dequeue()
{
	int n;
	if(tos2 == NULL)
	{
		while(tos1 != NULL)
		{
			push(&tos2, pop(&tos1));
		}
		n = pop(&tos2);
	}

	else
	{
		n = pop(&tos2);
	}
	printf("Value dequeued %d\n", n);
}

int main()
{
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	display();
	dequeue();
	display();
	dequeue();
	display();
	enqueue(5);
	display();
	return 0;
}

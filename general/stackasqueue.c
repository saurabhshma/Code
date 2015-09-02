#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int n;
	struct node *next;
}node;


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

void display_tos1(node *tos1)
{
	while(tos1 != NULL)
	{
		printf("%d ", tos1->n);
		tos1 = tos1->next;
	}
}

void display_tos2(node *tos2)
{
	if(tos2 != NULL)
	{
		display_tos2(tos2->next);
		printf("%d ", tos2->n);
	}
}

void display(node *tos1, node *tos2)
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

void enqueue(node **tos1, int n)
{
	push(tos1, n);
}

void dequeue(node **tos1, node **tos2)
{
	int n;
	if((*tos2) == NULL)
	{
		while((*tos1) != NULL)
		{
			n = pop(tos1);
			push(tos2, n);
		}
		n = pop(tos2);
	}

	else
	{
		n = pop(tos2);
	}
}

int main()
{
	node *tos1 = NULL, *tos2 = NULL;
	enqueue(&tos1, 1);
	enqueue(&tos1, 2);
	display(tos1, tos2);
	dequeue(&tos1, &tos2);
	display(tos1, tos2);
	return 0;
}

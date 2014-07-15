#include <stdio.h>
#include <stdlib.h>

struct stack
{
	int a;
	struct stack *next;
};

typedef struct stack node;

node *n1, *n2, *n3;

void display();
void create(int);
void push(node **, int);
int pop(node **);
void toh(int, node **, node **, node **);
int calc(int );

int main()
{
	int num; 
	n1 = NULL, n2 = NULL, n3 = NULL;
	printf("Enter the number of rings\n");
	scanf("%d", &num);
	create(num);
	printf("INITIAL STATE OF PEGS\n");
	display();
	printf("TOTAL NUMBER OF STEPS REQUIRE TO SOLVE ARE: %d\n", calc(num));
	toh(num, &n1, &n3, &n2);
	display();
	return 0;
}

void create(int num)
{
	node *temp, *temp1;
	temp1 = n1;
	int i;
	for(i = num; i > 0; i--)
	{
		temp = (node*)malloc(sizeof(node));
		temp->a = i;
		temp->next = temp1;
		temp1 = temp;
	}
	n1 = temp;
}

void display()
{
	node *temp;
	temp = n1;
	printf("Stack 1:\n");
	while(temp != NULL)
	{
		printf("%d\n", temp->a);
		temp = temp->next;
	}
	
	temp = n2;
	printf("Stack 2:\n");
	while(temp != NULL)
	{
		printf("%d\n", temp->a);
		temp = temp->next;
	}
	
	temp = n3;	
	printf("Stack 3:\n");
	while(temp != NULL)
	{
		printf("%d\n", temp->a);
		temp = temp->next;
	}

	printf("\n");
}

void push(node **temp, int n)
{
	node *temp1;
	temp1 = (node*)malloc(sizeof(node));
	temp1->a = n;
	temp1->next = *temp;
	*temp = temp1;
}

int pop(node **temp)
{
	int temp1;
	temp1 = (*temp)->a;
	*temp = (*temp)->next;
	return (temp1);
}

void toh(int n, node **p, node **i, node **t)
{
	if(n == 1)
	{
		push(&(*t), pop(&(*p)));
	}
	
	else
	{
		toh(n - 1, &(*p), &(*t), &(*i));
		display();
		push(&(*t), pop(&(*p)));
		display();
		toh(n - 1, &(*i), &(*p), &(*t));  
	}
}

int calc(int n)
{
	if(n == 1)
	{
		return 1;
	}

	else
	{
		return(2 * calc(n - 1) + 1);
	}
}

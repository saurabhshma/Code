#include <stdio.h>
#include <stdlib.h>

struct list
{
	int number;
	int *next;
};
typedef struct list node;
	
int main()
{
	int size;
	node *head;
	
	int create(node *a);
	int print(node *a);
	int count(node *a);

	head = (node *)malloc(sizeof(node));
	create(head);
	print(head);
	size = count(head);
	printf("Size is %d", size);
	return 0;
}

int create(node *list)
{
	printf("Enter Number. Enter 0 to the end.\n");
	scanf("%d", &list -> number);
	
	if(list -> number == 0)
		list -> next = NULL;
	
	else
	{	
		list -> next = (node *)malloc(sizeof(node));
		create(list -> next);
	}
}

int print(node *list)
{
	if(list -> next != NULL)
	{	
		printf("%d --> ", list -> number);
		if(list -> next -> next == NULL)
			printf("%d\n", list -> next -> number);
		print(list -> next);
	}
}
	
int count(node *list)
{
	if(list -> next == NULL)
		return 0;
	else
		return(1 + count(list -> next));
}

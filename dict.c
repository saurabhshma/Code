#include <stdio.h>
#include <stdlib.h>

void create();
void display();
void add();

struct list
{
	int n;
	struct list *next;
};
	
typedef struct list node;

node *head, *tail;

int main()
{
	int a;	
	head = (node*)malloc(sizeof(node));
	create();
	while(1)
	{	
		printf("Choose an option.\n1.ADD\n2.EXIT\n");
		scanf("%d", &a);
		switch(a)
		{
			case 1:
				add();
				break;
			case 2:
				exit(1);
			default:
				printf("Wrong choice. Choose a correct option.\n");
		}
	}
	return 0;
}

void create()					/*Create circular linked list*/
{
	node *temp;
        temp = head;
	char choice;
	printf("Start entering the elements in increasing order.\n");
	do
	{
		scanf("%d", &temp->n);
		printf("Want to add another node? Press(y/n)\n");
		scanf("\n%c", &choice);
		if(choice == 'y')
		{
			temp->next = (node*)malloc(sizeof(node));
			temp = temp->next;
		}
		else
		{
			temp->next = head;
			tail = temp;
			break;
		}
		printf("Enter the element\n");
	}while(1);	
	printf("Linked List created successfully\n");
	display();
}

void display()
{
	node *temp;
	temp = head;
	printf("Linked list is:\n");
	do
	{
		printf("%d", temp->n);
		if(temp->next != head)
		{
			printf("-->");
		}
		temp = temp->next;
	}while(temp != head);
	printf("\n");
}

void add()
{
	int n;
	node *temp, *temp1;
	temp = head;
	printf("Enter the number you want to add\n");
	scanf("%d", &n);
	
	if(head->n >= n)
	{
		temp1 = (node*)malloc(sizeof(node));
		temp1->n = n;
		temp1->next = head;
		head = temp1;
		tail->next = head;
	}

	else if(n > tail->n)
	{
		temp1 = (node*)malloc(sizeof(node));
		temp1->n = n;
		temp1->next = head;
		tail->next = temp1;
		tail = tail->next;
	}

	else
	{
		while(n > temp->n)
		{
			temp = temp->next;
		}
		
		temp1 = temp;

		while(temp->next != temp1)
		{
			temp = temp->next;
		}
		temp->next = (node*)malloc(sizeof(node));
		temp->next->n = n;
		temp->next->next = temp1;
	}

	display();
}


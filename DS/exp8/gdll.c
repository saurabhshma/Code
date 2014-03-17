#include <stdio.h>
#include <stdlib.h>

void create();
void display();
void ins_beg();
void ins_end();
void insert();
void del_beg();
void del_end();
void delete();

struct list
{
	int n;
	struct list *next;
	struct list *prev;
};
	
typedef struct list node;
	
node *head;
node *tail;

int main()
{
	char n;
	head = (node*)malloc(sizeof(node));
	create();
	while(1)
	{
		printf("Choose the operation you want to do on linked list\n");
		printf("1. INSERT AT BEGINNING\n2. INSERT AT END\n3. INSERT AT GIVEN POSITION\n4. DELETE FROM BEGINNING\n5. DELETE FROM END\n6. DELETE FROM GIVEN POSITION\n7. EXIT\n");
		scanf("\n%c", &n);
		switch(n)
		{
		case '1':	
			ins_beg();
			break;
		case '2':
			ins_end();
			break;
		case '3':
			insert();
			break;
		case '4':
			del_beg();
			break;
		case '5':
			del_end();
			break;
		case '6':
			delete();
			break;
		case '7':
			exit(1);
		default:
			printf("Wrong Choice\n");
		}
	}
		return 0;
}

void create()
{
	node *temp;
        temp = head;
	char choice;
	temp->prev = NULL;
	printf("Start entering the elements\n");
	do
	{
		scanf("%d", &temp->n);
		printf("Want to add another node? Press(y/n)\n");
		scanf("\n%c", &choice);
		if(choice == 'y')
		{
			temp->next = (node*)malloc(sizeof(node));
			temp->next->prev = temp;
			temp = temp->next;
		}
		else
		{
			temp->next = NULL;
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
	printf("LIST is:\n");
	while(temp != NULL)
	{
		printf("%d", temp->n);
		if(temp->next != NULL)
		{
			printf("-->");
		}
		temp = temp->next;
	}
	printf("\n");
}

void ins_beg()
{
	node *temp;
	temp = (node*)malloc(sizeof(node));
	printf("Enter the value of new node\n");
	scanf("%d", &temp->n);
	temp->next = head;
	temp->next->prev = temp;
	temp->prev = NULL;
	head = temp;
	display();
}

void ins_end()
{
	tail->next = (node*)malloc(sizeof(node));
	printf("Enter the value of new node\n");
	scanf("%d", &tail->next->n);
	tail->next->prev = tail;
	tail = tail->next;
	tail->next = NULL;
	display();
}

void insert()
{
	node *temp, *temp1;
	temp = head;
	int n, i;
	printf("Enter the number of node after which you want to insert the new node\n");
	scanf("%d", &n);
	for(i = 0; i < (n - 1); i++)
	{
		temp = temp->next;
	}
	temp1 = (node*)malloc(sizeof(node));
	printf("Enter the element\n");
	scanf("%d", &temp1->n);
	temp1->next = temp->next;
	temp->next = temp1;
	temp1->prev = temp;
	temp1->next->prev = temp1;
	display();
}

void del_beg()
{
	node *temp;
	temp = head->next;
	free(head);
	head = temp;
	head->prev = NULL;
	display();	
}

void del_end()
{
	node *temp;
	temp = tail->prev;
	free(tail);
	tail = temp;
	tail->next = NULL;
	display();
}

void delete()
{
	node *temp, *temp1;
	temp = head;
	int n, i;
	printf("Enter which node you want to delete\n");
	scanf("%d", &n);
	for(i = 1; i < (n - 1); i++)
	{
		temp = temp->next;
	}
	temp1 = temp->next;
	temp->next = temp1->next;
	temp1->next->prev = temp;
	free(temp1);
	display();
}

OUTPUT:

Start entering the elements
1
Want to add another node? Press(y/n)
y
Enter the element
2
Want to add another node? Press(y/n)
y
Enter the element
3
Want to add another node? Press(y/n)
n
Linked List created successfully
LIST is:
1-->2-->3
Choose the operation you want to do on linked list
1. INSERT AT BEGINNING
2. INSERT AT END
3. INSERT AT GIVEN POSITION
4. DELETE FROM BEGINNING
5. DELETE FROM END
6. DELETE FROM GIVEN POSITION
7. EXIT
5
LIST is:
1-->2
Choose the operation you want to do on linked list
1. INSERT AT BEGINNING
2. INSERT AT END
3. INSERT AT GIVEN POSITION
4. DELETE FROM BEGINNING
5. DELETE FROM END
6. DELETE FROM GIVEN POSITION
7. EXIT
7


#include <stdio.h>
#include <stdlib.h>

void create();
void display();
void ins();
void del();

struct queue
{
	int n;
	struct queue *next;
};
	
typedef struct queue node;
	
node *head;
node *tail;

int main()
{
	char n;
	head = (node*)malloc(sizeof(node));
	create();
	while(1)
	{
		printf("Choose an option.\n");
		printf("1. INSERT\n2. DELETE\n3. EXIT\n");
		scanf("\n%c", &n);
		switch(n)
		{
		case '1':	
			ins();
			break;
		case '2':
			del();
			break;
		case '3':
			exit(1);
			break;
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
	printf("Start entering the elements\n");
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
			temp->next = NULL;
			tail = temp;
			break;
		}
		printf("Enter the element\n");
	}while(1);	
	printf("Queue created successfully\n");
	display();
}

void display()
{
	node *temp;
	temp = head;
	printf("Queue is:\n");
	while(temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

void ins()
{
	tail->next = (node*)malloc(sizeof(node));
	printf("Enter the value of new node\n");
	scanf("%d", &tail->next->n);
	tail = tail->next;
	tail->next = NULL;
	display();
}

void del()
{
	if(head == NULL)
	{
		printf("Underflow!\n");
	}

	else
	{
		node *temp;
		temp = head->next;
		free(head);
		head = temp;
		display();	
	}
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
Queue created successfully
Queue is:
1
2
3
Choose an option.
1. INSERT
2. DELETE
3. EXIT
1
Enter the value of new node
2
Queue is:
1
2
3
2
Choose an option.
1. INSERT
2. DELETE
3. EXIT
3


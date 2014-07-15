#include <stdio.h>
#include <stdlib.h>

void create();
void display();
//void reverse();
 
struct list
{
	int n;
	struct list *next;
};
	
typedef struct list node;

node* reverse(node *);
	
node *head, *a;

int main()
{
	head = (node*)malloc(sizeof(node));
	create();
	printf("Linked list after reversing\n");
	reverse(head);
	head->next = NULL;
	head = a;
	display();
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

/*void reverse()                      //iterative
{
	node *temp1, *temp2, *temp3;
	temp1 = head;
	temp2 = head->next;
	while(temp2 != NULL)
	{
		temp3 = temp2->next;
		temp2->next = temp1;
		temp1 = temp2;
		temp2 = temp3;
	}
	head->next = NULL;
	head = temp1;
	display();
}*/

node* reverse(node *temp)      //recursive
{
	node *temp1;
	if(temp->next == NULL)
	{
		a = temp;
		return (temp);
	}

	else
	{
		temp1 = reverse(temp->next);
		temp1->next = temp;
		return(temp1->next);
	}
}

#include <stdio.h>
#include <stdlib.h>

void display();
void create();
 
struct edge
{
	int e;
	struct edge *next;
};

struct list
{
	int vertex;
	struct list *next_v;
	struct edge *next_e;
};


typedef struct list node_1;
typedef struct edge node_2;

node_1 *head;
int v;

int main()
{
	int i;
	node_1 *temp;
	printf("Enter the number of vertices\n");
	scanf("%d", &v);
	head = (node_1*)malloc(sizeof(node_1));
	temp = head;
	for(i = 1; i <= v ; i++)
	{
		temp->vertex = i;
		temp->next_e = NULL;
		if(i < v)
		{
			temp->next_v = (node_1*)malloc(sizeof(node_1*));
			temp = temp->next_v;
		}
	}
	temp->next_v = NULL;
	create();
	return 0;
}

void display()
{
	node_1 *temp;
	node_2 *temp1;
	temp = head;
	temp1 = temp->next_e;
	printf("Adjacency List is:\n");
	while(temp != NULL)
	{
		printf("%d -> ", temp->vertex);
		do
		{
			if(temp1 == NULL)
			{
				printf("\n");
				break;
			}
			
			else
			{
				printf("%d ", temp1->e);
				if(temp1->next != NULL)
				{
					printf("-> ");
				}
			}
			temp1 = temp1->next;
		}while(1);
		temp = temp->next_v;
	}
}

void create()
{
	int x, y;
	char choice;
	node_1 *temp;
	do
	{
		temp = head;
		printf("Enter the edge\n");
		scanf("%d %d", &x, &y);
		while(1)
		{
			if(temp->vertex == x)
			{
				break;
			}
			
			else
			{
				temp = temp->next_v;
			}
		}
		printf("temp->vertex %d\n", temp->vertex);
		while(temp->next_e != NULL)
		{
			printf("%d\n", temp->next_e->e);
			temp->next_e = temp->next_e->next;
		}
		temp->next_e = (node_2*)malloc(sizeof(node_2));
		temp->next_e->e = y;
		temp->next_e->next = NULL;
		display();
		printf("Enter next edge? (y/n)\n");
		scanf("\n%c", &choice);
		if(choice == 'n')
		{
			break;
		}
	}while(1);
	display();
}

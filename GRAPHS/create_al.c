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
	struct edge *next_e;
};


typedef struct list node_1;
typedef struct edge node_2;

node_1 *V;
int n;

int main()
{
	int i;
	printf("Enter the number of vertices\n");
	scanf("%d", &n);
	V = (node_1*)malloc(n  * sizeof(node_1));
	for(i = 0; i < n ; i++)
	{
		V[i].vertex = i + 1;
		V[i].next_e = NULL;
	}
	create();
	return 0;
}

void display()
{
	int i;
	node_2 *temp;
	printf("Adjacency list is :\n");
	for(i = 0; i < n; i++)
	{
		temp = V[i].next_e;
		printf("%d", V[i].vertex);
		do
		{
			if(temp != NULL)
			{
				printf(" -> %d", temp->e);
				temp = temp->next;
			}
		
			else
			{
				break;
			}
		}while(1);
		printf("\n");
	}
}

void create()
{
	int x, y, i;
	char choice;
	node_2 *temp;
	do
	{
		printf("Enter the edge\n");
		scanf("%d %d", &x, &y);
		for(i = 0; i < n; i++)
		{
			if(V[i].vertex == x)
			{
				break;
			}
		}
		if(V[i].next_e == NULL)
		{
			V[i].next_e = (node_2*)malloc(sizeof(node_2));
			V[i].next_e->e = y;
			V[i].next_e->next =NULL;
		}
		else
		{
			temp = V[i].next_e;
			while(temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = (node_2*)malloc(sizeof(node_2));
			temp->next->e = y;
			temp->next->next = NULL;
		}
		printf("Enter next edge? (y/n)\n");
		scanf("\n%c", &choice);
		if(choice == 'n')
		{
			break;
		}
	}while(1);
	display();
}

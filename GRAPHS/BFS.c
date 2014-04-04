#include <stdio.h>
#include <stdlib.h>

void display_queue();
void display();
void create();
 
struct list
{
	int val;
	char colour;
	struct edge *next_e;
};

struct edge
{
	struct list *ptr;
	struct edge *next;
};

struct queue
{
	struct list *ptr;
	struct queue *next;
};

typedef struct list node_1;
typedef struct edge node_2;
typedef struct queue node_3;

node_1 *V;
int n;
node_3 *start, *end;

void BFS();
void enqueue(node_1*);
node_1* dequeue();

int main()
{
	int i;
	printf("Enter the number of vertices\n");
	scanf("%d", &n);
	V = (node_1*)malloc(n  * sizeof(node_1));
	for(i = 0; i < n ; i++)
	{
		V[i].val = i + 1;
		V[i].colour = 'w';
		V[i].next_e = NULL;
	}
	create();
	printf("BFS\n");
	BFS();
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
		printf("%d", V[i].val);
		do
		{
			if(temp != NULL)
			{
				printf(" -> %d", temp->ptr->val);
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
		if(V[x - 1].next_e == NULL)
		{
			V[x - 1].next_e = (node_2*)malloc(sizeof(node_2));
			V[x - 1].next_e->ptr = &V[y - 1];
			V[x - 1].next_e->next = NULL;
		}

		else
		{
			temp = V[x - 1].next_e;
			while(temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = (node_2*)malloc(sizeof(node_2));
			temp->next->ptr = &V[y - 1];
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

void BFS()
{
	int s;
	node_1 *u;
	node_2 *temp;
	printf("Enter source vertex\n");
	scanf("%d", &s);
	V[s - 1].colour = 'g';
	enqueue(&V[s - 1]);
	printf("Vertices discovered in BFS:\n");
	while(start != NULL)
	{
		u = dequeue();
		temp = u->next_e;
		while(temp != NULL)
		{
			if(temp->ptr->colour == 'w')
			{
				temp->ptr->colour = 'g';
				enqueue(temp->ptr);
			}
			temp = temp->next;
		}
		u->colour = 'b';
		if(u->colour == 'b')
		{
			printf("%d\n", u->val);
		}
	}
	
}

void enqueue(node_1 *a)
{
	if(start == NULL)
	{
		start = (node_3*)malloc(sizeof(node_3));
		start->ptr = a;
		start->next = NULL;
		end = start;
	}
	
	else
	{
		end->next = (node_3*)malloc(sizeof(node_3));
		end->next->ptr = a;
		end->next->next = NULL;
		end = end->next;
	}
}

node_1* dequeue()
{
	node_1 *temp1;
	node_3 *temp;
	temp1 = start->ptr;
	temp = start;
	start = start->next;
	free(temp);
	return(temp1);	
}

void display_queue()
{
	node_3 *temp;
	temp = start;
	printf("Queue is:\n");
	while(temp != NULL)
	{
		printf("%d ", temp->ptr->val);
		temp = temp->next;	
	}
	printf("\n");
}

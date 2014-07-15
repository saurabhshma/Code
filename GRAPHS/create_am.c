#include <stdlib.h>
#include <stdio.h>

int v;
int **A;
void create_am();
void display_am();

int main()
{
	int i, j;
	printf("Enter number of vertices\n");
	scanf("%d", &v);
	create_am();
	free(A);
	return 0;
}

void create_am()
{
	int x, y, i, j;
	char choice;
	int *temp;
	A = (int**)malloc(v * sizeof(int*));
	temp = (int*)malloc(v * sizeof(int));
	for (i = 0; i < v; i++) 
	{
		A[i] = temp + (i * v);
	}
	for(i = 0; i < v; i++)
	{
		for(j = 0; j < v; j++)
		{
			A[i][j] = 0;
		}
	}
	while(1)
	{
		printf("Enter the edge\n");
		scanf("%d %d", &x, &y);
		A[x - 1][y - 1] = 1;
		printf("Enter next edge? (y/n)\n");
		scanf("\n%c", &choice);
		if(choice == 'n')
		{
			break;
		}
	}
	display_am();
}

void display_am()
{
	int i, j;
	printf("Adjacency Matrix is:\n");
	for(i = 0; i < v; i++)
	{
		for(j = 0; j < v; j++)
		{
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
}

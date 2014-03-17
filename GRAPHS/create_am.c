#include <stdio.h>

void create_am();
void display_am();
int v;
int A[][v];

int main()
{
	create_am();
	return 0;
}

void create_am()
{
	int x, y, i;
	printf("Enter Number of vertices\n");
	scanf("%d", &v);
	printf("Enter edges one by one\n");
	for(i = 0; i < v; i++)
	{
		scanf("%d %d", &x, &y);
		A[x - 1][y - 1] = 1;	
	}
	display_am();
}

void display_am()
{
	int i, j;
	for(i = 0; i < v; i++)
	{
		for(j = 0; j < v; j++)
		{
			printf("%d ", A[i][j]); 
		}
		printf("\n");
	}
}


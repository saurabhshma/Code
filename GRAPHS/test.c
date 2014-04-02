#include <stdio.h>
#include <stdlib.h>

struct ABC
{
	int n;
};

typedef struct ABC node;
int x;
node *A;

int main()
{
	int i, j;
	printf("Enter x\n");
	scanf("%d", &x);
	A = (node*)malloc(x * sizeof(node));
	for(i = 0; i < x; i++)
	{
			scanf("%d", &A[i].n);
	}
	for(i = 0; i < x; i++)
	{
			printf("%d\n", A[i].n);
	}
	free(A);	
	return 0;
}

#include <stdio.h>

int main()
{
	int A[10] = {1, 2, 5, 3, 10, 20, 4, 7, 9, 17}, largest = 20, i, j;
	for(i = 0; i < (sizeof(A) / sizeof(A[0])); i++)
	{
		for(j = 0; j < A[i]; j++)
		{
			printf("* ");
		}
		printf("\n");
	}
	return 0;
}

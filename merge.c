#include <stdio.h>

int merge(int size, int size_1, int A[], int B[]);

int main()
{
	int size, size_1;
	printf("Enter the size of 1st array\n");
	scanf("%d", &size);
	printf("Enter the size of 2nd array\n");
	scanf("%d", &size_1); 
	int A[size], B[size_1], i;
	printf("Enter 1st array in increasing order \n");
	for(i = 0; i < size; i++)
		scanf("%d", &A[i]);
	printf("Enter 2nd array in increasing order \n");
	for(i = 0; i < size_1; i++)
		scanf("%d", &B[i]);
	merge(size, size_1, A, B);
	return 0;
}

int merge(int size, int size_1, int A[], int B[])
{
	int tot_size = size + size_1;
	int C[tot_size], i = 0, j = 0, k;
	for(k = 0; k < tot_size; k++)
	{		
		if(i > (size - 1))
		{
			C[k] = B[j];
			j++;
		}
		else if(j > (size_1 - 1))
		{
			C[k] = A[i];
			i++;
		}	
		else if(A[i] < B[j])
		{
			C[k] = A[i];
			i++;
		}	
		else
		{
			C[k] = B[j];
			j++; 
		}
	}
		
	printf("Array after Merging\n");
	for(k = 0; k < tot_size; k++)
		printf("%d  ", C[k]);
	printf("\n");
}


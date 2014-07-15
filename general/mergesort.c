#include <stdio.h>

int mergesort(int a, int b, int A[], int B[]);
int merge(int a, int b, int A[], int B[]);

int main()
{
	int size, a = 0, b, i;

	printf("Enter the size of array\n");
	scanf("%d", &size); 
	int A[size], B[size];
	printf("Enter array\n");
	for(i = 0; i < size; i++)
		scanf("%d", &A[i]);
	b = size - 1;
	mergesort(a, b, A, B);
	printf("Array after mergesort\n");
	for(i = 0; i < size; i++)
		printf("%d ", B[i]);
	printf("\n");
	return 0;
}

int mergesort(int a, int b, int A[], int B[])
{
	int mid = (a + b) / 2;

	if(a == b)
		return A[a];
	else
	{
		mergesort(a, mid, A, B);
		mergesort((mid + 1), b, A, B);
		merge(a, b, A, B);  
	}
}

int merge(int a, int b, int A[], int B[])
{
	int mid = (a + b) / 2;
	int i = a, j = mid + 1, k;
	for(k = a; k <= b; k++)
	{	
		if(i > mid)
		{
			B[k] = A[j];
			j++;
		}
		else if(j > b)
		{
			B[k] = A[i];
			i++;
		}	
		else if(A[i] < A[j])
		{
			B[k] = A[i];
			i++;
		}	
		else
		{
			B[k] = A[j];
			j++;
		}
	}
	for(k = a; k <= b; k++)
		A[k] = B[k];
}

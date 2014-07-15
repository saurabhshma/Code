#include <stdio.h>
#define SIZE 5

int A[SIZE];

void display();
void swap(int *a, int *b);
void quicksort(int a, int b);
int partition(int a, int b);

int main()
{
	int i;
	printf("Enter start entering elements\n");
	for(i = 0; i < SIZE; i++)
	{
		scanf("%d", &A[i]);
	}
	printf("Array is : \n");
	display();
	quicksort(0, 4);
	printf("Array after applying quicksort\n");
	display();
	return 0;
}

void display()
{
	int i;
	for(i = 0; i < SIZE; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}

void quicksort(int a, int b)
{
	int part;
	if(a <= b)
	{
		part = partition(a, b);
		quicksort(a, part - 1);
		quicksort(part + 1, b);
	}
}

int partition(int a, int b)
{
	int x = b, i = a, j;
	for(j = a; j < b; j++)
	{
		if(A[j] <= A[x])
		{
			swap(&A[j], &A[i]);
			i = i + 1;	
		}
	}
	swap(&A[i], &A[x]);
	display();
	return (i);
}

void swap(int *a, int *b)
{
	int temp;
	temp = *a + *b;
	*a = temp - *a;
	*b = temp - *a;
}

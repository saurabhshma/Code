#include <stdio.h>

int ins_sort(int A[],int n); 
int swap(int *a, int *b);

int main()
{
	int n;
	
	printf("Enter the number of elements\n");	
	scanf("%d", &n);
	
	int A[n], i;
	
	printf("Enter the elements\n");
	
	for(i = 0; i < n; i++)
		scanf("%d", &A[i]);
	
	ins_sort(A, n);
	printf("Sorted Array after applying Insertion Sort \n");

	for(i = 0; i < n; i++)
		printf("%d ", A[i]);

	
	printf("\n");
	return 0; 
}

int ins_sort(int A[],int n)
{
	int i, j;
	for(i = 1; i < n; i++)
	{
		for(j = i; j > 0; j--)
			{
				if(A[j] < A[j - 1])
					swap(&A[j], &A[j - 1]);
				
				else
					break;
			}
	}
}
	
int swap(int *a, int *b)
{
	int sum = *a + *b;
	*a = sum - *a;
	*b = sum - *a;
}

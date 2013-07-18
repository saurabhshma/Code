#include <stdio.h>

int sel_sort(int A[],int n); 
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
	
	sel_sort(A, n);
	printf("Sorted Array after applying Selection Sort \n");

	for(i = 0; i < n; i++)
		printf("%d ", A[i]);

	
	printf("\n");
	return 0; 
}

int sel_sort(int A[],int n)
{
	int i, j, smallest, index;
	for(i = 0; i < n; i++)
	{
		index = i;
		for(j = i + 1; j < n; j++)
			{
				if(A[j] < A[index])
				index = j;
			}
		swap(&A[i], &A[index]);
	}

}
	
int swap(int *a, int *b)
{
	int sum = *a + *b;
	*a = sum - *a;
	*b = sum - *a;
}

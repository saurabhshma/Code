#include <stdio.h>
#include <stdlib.h>

int b_search(int A[],int n, int number);

int main()
{
	int n, i, number;
	printf("Enter number of elements\n");
	scanf("%d", &n);
	int A[n];
	printf("Enter the elements in increasing order\n");
	for(i = 0; i < n; i++)
		scanf("%d", &A[i]);
	printf("Enter the number you want to search\n");
		scanf("%d", &number);
	
	n = b_search(A, n, number);
	printf("Number found at position %d\n", n + 1);
	return 0;	
}

int b_search(int A[], int n, int number)
{
	int first = 0, last = n - 1;
	int mid = (first + (last + 1)) / 2;
	do
	{
	
		if(A[mid] > number)
		{
			last = mid;
			mid = (first + (last + 1)) / 2;
		}
	
		else if(A[mid] < number)
		{
			first = mid;
			mid = (first + (last + 1)) / 2;
		}
	
		else
		{
			return mid;
		}
	}while(first != (last));
	
	printf("Element not found\n");
	exit(1);
}	


#include <stdio.h>
#include <stdlib.h>

void b_search(int A[],int n, int number);

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
	
	b_search(A, n, number);
	return 0;	
}

void b_search(int A[], int n, int number)
{
	int first = 0, last = n - 1;
	int mid = (first + last) / 2;
	do
	{
		if(A[mid] == number)
		{
			printf("Number found at position %d\n", mid + 1);
			exit(1);
		}	
			
		else if(A[mid] > number)
		{
			last = mid - 1;
			mid = (first + (last)) / 2;
		}
	
		else
		{
			first = mid + 1;
			mid = (first + (last)) / 2;
		}
	}while((last >= first) && (first <= last));

	printf("Element not found!!!\n");
}	


#include <stdio.h>
#define SIZE 5 

int heapsize;
int A[SIZE];
void display();
void maxheapify(int x);
void buildheap();
void heapsort();
int left(int x);
int right(int x);
int parent(int x);

int main()
{
	int i;
	heapsize = SIZE - 1;
	printf("Enter start entering elements\n");
	for(i = 0; i < SIZE; i++)
	{
		scanf("%d", &A[i]);
	}
	printf("Array is : \n");
	display();
	heapsort();
	printf("Array after applying heapsort\n");
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

int left(int x)
{
	return ((2 * x) + 1);
}

int right(int x)
{
	return ((2 * x) + 2);	
}

int parent(int x)
{
	int temp;
	if(x % 2 == 0)
	{
		temp = (x - 1) / 2;
	}
	
	else
	{
		temp = x / 2;
	}
	return (temp);
}

void maxheapify(int x)
{
	int l, r, p;
	int largest, temp;

	l = left(x);
	r = right(x);
	p = parent(x);
	if(l <= heapsize && A[x] < A[l])
	{
		largest = l;
	}
	
	else
	{
		largest = x;
	}
	
	if(r <= heapsize && A[r] > A[largest])
	{
		largest = r;
	}

	if(largest != x)
	{
		temp = A[x];
		A[x] = A[largest];
		A[largest] = temp;
		maxheapify(largest);
	}
}

void buildheap()
{
	int temp, i;
	if(heapsize % 2 == 0)
	{
		temp = (heapsize - 1) / 2;
	}
	
	else
	{
		temp = heapsize / 2;
	}

	for(i = temp; i >= 0; i--)
	{
		maxheapify(i);
	}
}

void heapsort()
{
	int i, temp;
	buildheap();
	for(i = SIZE - 1; i > 0; i--)
	{
		temp = A[0];
		A[0] = A[i];
		A[i] = temp;
		heapsize = heapsize - 1;
		maxheapify(0);
	}
}

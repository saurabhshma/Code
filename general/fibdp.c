#include <stdio.h>
#define SIZE 50
long int A[SIZE];

long int dpfib(int n);

int main()
{
	int i;	
	A[0] = 0, A[1] = 1;
	for(i = 2; i < SIZE; i++)
		A[i] = -1;
	int n = 40;
	printf("%d fib no %ld\n", n, dpfib(n));
	return 0;
}

long int dpfib(int n)
{
	if(A[n - 1] == -1)
		A[n - 1] = dpfib(n - 1);
	if(A[n - 2] == -1)
		A[n - 2] = dpfib(n - 2);
	return(A[n - 1] + A[n - 2]);
}

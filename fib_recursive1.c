#include <stdio.h>

int fib(int n);

int main()
{
	int n, a;
	printf("Enter value of N\n");
	scanf("%d", &n);
	a = fib(n);
	printf("The required fibonacci number is %d \n", a);
	return 0;
}

int fib(int n)
{
	int a;
	if(n <= 1)
	return 0;
	
	if(n == 2)
	return 1;

	a = fib(n - 1) + fib(n - 2);	
	return a;
}

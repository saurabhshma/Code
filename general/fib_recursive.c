#include <stdio.h>

int fib(int, int, int);

int main()
{
	int n, first = 0, second = 1;
	printf("Enter the value of n\n");
	scanf("%d", &n);
	printf("Fibonacci Series upto %d terms\n", n);
	if(n == 1)
		printf("%d\n", first);
	else if(n == 2)
		printf("%d\n%d\n", first, second);
	else
	printf("%d\n%d\n", first, second);
	fib(first, second, n); 
	return 0; 
}

int fib(int first, int second, int n)
{
	int third;
	if((n - 2) == 0) {
		return 0;
	}
	else {
		third = first + second;
		printf("%d \n", third);
		first = second;
		second = third;
		fib(first, second, --n);
	}
}

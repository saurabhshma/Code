#include <stdio.h>

int calc(int);

int main()
{
	int n, result;
	printf("Enter the number of rings\n");
	scanf("%d", &n);
	result = calc(n);
	printf("Number of steps required to solve the problem is: %d\n", result);
	return 0;
}

int calc(int n)
{
	if(n == 1)
	{
		return 1;
	}

	else
	{
		return(2 * calc(n - 1) + 1);
	}
}

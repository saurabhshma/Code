#include <stdio.h>

int print(int);

int main()
{
	print(10);
	return 0;
}

int print(int a)
{
	int x;
	if(a == 1)
	{
		printf("%d\n", a);
		return 1;
	}

	else
	{
		int temp = print(a-1);
		printf("temp %d at a = %d\n", temp, a);
		x = temp + 1;
		printf("%d\n", x);
	}
}


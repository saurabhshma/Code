#include <stdio.h>

/*int f(int a)
{
	printf("%d ", a++);
	return(++a);
}*/
int *f(int a);
int main()
{
	int *i = f(1);
	printf("\n");
	return 0;
}

int *f(int a)
{
	int x = 10;
	printf("%d ", x);
	return (&x);
}


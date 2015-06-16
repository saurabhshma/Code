#include <stdio.h>

int main()
{
	int a, b, x;
	scanf("%d %d", &a, &b);
	do
	{
		x = a % b;
		a = b;
		b = x;
	} while(x != 0);
	printf("%d\n", a);
	return 0;
}

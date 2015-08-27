#include <stdio.h>

int main()
{	
	int i, n, x, sign = 1;
	int count;
	scanf("%d", &n);
	count = n;
	x = 1;
	for(i = 1; i <= count; i++)
	{
		printf("%d ", x);
		if (x < count) {
			x = x + sign;
		} else {
			sign = -1;
			x = x + sign;
		}
		if (x == count)
			sign = -1;
		x = x + sign;
	}

	printf("\n");
	return 0;
}

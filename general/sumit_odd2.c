#include <stdio.h>

int main()
{	
	int i, n, x, sign = 2;
	int count;
	scanf("%d", &n);
	count = n - 1;
	x = 2;
	for(i = 1; i <= count; i++)
	{
		printf("%d ", x);
		if ((x + sign) > n && (x + sign) > (n + 1)) {
			sign = sign * (-1);
			x += sign;
		} else if ((x + sign) > n) {
			sign = sign * (-1);
		} else {
			x += sign;
		}
	}

	printf("\n");
	return 0;
}

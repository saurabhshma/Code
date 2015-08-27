#include <stdio.h>

int main()
{	
	int i, n, x = 1, sign = 2;
	scanf("%d", &n);
	if(n % 2 != 0)
	{
		for(i = 1; i <= n; i++)
		{
			if(i == n / 2 + 1)
				sign = sign * (-1);
			printf("%d ", x);
			x = x + sign;
		}
	}

	else
	{
		for(i = 1; i <= n; i++)
		{
			if(i == n / 2)
				sign = 0;
			else if(i > n / 2)
				sign = -2;
			printf("%d ", x);
			x = x + sign;
		}
	}
	printf("\n");
	return 0;
}

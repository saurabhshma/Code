#include <stdio.h>

int main(int c, char *arg[])
{	
	int i, n, x, sign = 2;
	char ch = arg[1][0];
	scanf("%d", &n);
	if(ch == 'o')
	{
		x = 1;
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
	}

	else
	{
		x = 2;
		if(n % 2 != 0)
		{
			for(i = 1; i <= n -1; i++)
			{
				if(i == n / 2)
					sign = 0;
				else if(i > n / 2)
					sign = -2;
				printf("%d ", x);
				x = x + sign;
			}
		}

		else
		{
			for(i = 1; i <= n - 1; i++)
			{
				if(i == n / 2)
					sign = -2;
				printf("%d ", x);
				x = x + sign;
			}
		}

	}
	printf("\n");
	return 0;
}

#include <stdio.h>
 
int main()
{
	long long int moves, x, y, min;
	int t, i;
	scanf("%d", &t);
	for(i = 0; i < t; i++)
	{
		scanf("%lld %lld", &x, &y);
		if(x < 0)
		{
			x = -x;
		}
		if(y < 0)
		{
			y = -y;
		}
		if(x < y)
		{
			min = x;
		}
		else
		{
			min = y;
		}
		if(x == y)
		{
			moves = 2 * x;
		}
		else if(x < y)
		{
			if((y - min) % 2 == 0)
			{
				moves = 2 * min + 2 * (y - min);
			}
			else
			{
				moves = 2 * min + 2 * (y - min) - 1;
			}
		}
		else
		{
			if((x - min) % 2 == 0)
			{
				moves = 2 * min + 2 * (x - min);
			}
			else
			{
				moves = 2 * min + 2 * (x - min) + 1;
			}
		
		}
		printf("%lld\n", moves);
	}
	return 0;
}

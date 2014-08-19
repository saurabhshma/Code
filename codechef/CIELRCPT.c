#include <stdio.h>

int main()
{
	int t, p, result, mod, i, j, x;
	scanf("%d", &t);
	for(i = 0; i < t; i++)
	{
		result = 0;
		x = 2048;
		scanf("%d", &p);
		for(j = 11; j >= 0; j--)
		{
			if(x > p)
			{
				x = x >> 1;
			}
			else
			{
				result += p / x;
				mod = p % x;
				if(mod == 0)
				{
					break;
				}
				else
				{
					p = mod;
				}
			}
		}
		printf("%d\n", result);
	}
	return 0;
}

#include <stdio.h>

int main()
{
	int t, n, i, j;
	double l, d, x, temp, result, result_temp, a, b;
	scanf("%d", &t);
	for(i = 0; i < t; i++)
	{
		x = 0;
		result = 0;
		scanf("%d %lf", &n, &l);
		scanf("%lf", &a);
		for(j = 0; j < n - 1; j++)
		{
			temp = 0;
			scanf("%lf", &b);
			d = (l - (b - a)) / 2;
			if(a - d < x)
			{
				temp = d - a + x;
			}
			result_temp = d + temp;
			if(result_temp > result)
			{
				result = result_temp;
				a = b + result;
				x = a;
			}
			//printf("a %lf b %lf\nd %lf temp %lf\nres_temp %lf result %lf\n", a, b, d, temp, result_temp, result);
			//a = a + result;
			//x = a;
		}
		printf("%lf\n", result);
	} 
	return 0;
}

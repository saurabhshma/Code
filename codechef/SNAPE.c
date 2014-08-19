#include <stdio.h>
#include <math.h>

int main()
{
	int t, b, ls, i;
	float rs;
	scanf("%d", &t);
	for(i = 0; i < t; i++)
	{
		scanf("%d %d", &b, &ls);
		rs = sqrt(ls * ls - b * b);
		printf("%f ", rs);
		rs = sqrt(ls * ls + b * b);
		printf("%f\n", rs);
	}
	return 0;
}

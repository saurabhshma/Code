#include <stdio.h>

int comb(int n, int r);

int main()
{
	float n, r, result;
	printf("Enter n and r\n");
	scanf("%f %f", &n, &r);
	result = comb(n, r);
	return 0;
}

int comb(int n, int r)
{
	float result, a;

	if(r == 1)
		return n; 

	else
		return ((n - r + 1)  * comb(n, r - 1) ) / r;
}

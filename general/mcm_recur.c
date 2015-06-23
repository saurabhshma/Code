#include <stdio.h>
#include <limits.h>

int mcm(int a, int b);
int P[7] = {30, 35, 15, 5, 10, 20, 25};

int main()
{
	int result = mcm(1, 6);
	printf("Result: %d\n", result);
	return 0;	
}

int mcm(int a, int b)
{
	int k, min = INT_MAX, temp;
	if(a == b)
		return 0;
	else
	{
		for(k = a; k < b; k++)
		{
			temp = (mcm(a, k)+ mcm(k + 1, b) + P[a - 1] * P[b] * P[k]);
			if(temp < min)
			{
				min = temp;	
			}
		}
		return min;
	}
}

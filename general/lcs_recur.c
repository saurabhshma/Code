#include <stdio.h>

char X[] = "abcbdac";
char Y[] = "bdcaba";

int lcs(int a, int b);

int main()
{
	int result = lcs(7, 6);
	printf("Result : %d\n", result);	
	return 0;
}

int lcs(int a, int b)
{
	int x, y;
	if( a == 0 || b == 0)
		return 0;
	else
	{
		if(X[a - 1] == Y[b - 1])
			return(1 + lcs(a - 1, b - 1));
		else
		{
			x = lcs(a - 1, b);
			y = lcs(a, b - 1);
			if(x > y)
				return x;
			else
				return y;		
		}
	} 
}

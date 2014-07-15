#include <stdio.h>
 
#define MOD 1000000009
 
long long fact(long long n);
long long Power(int a, int b);
int main()
{
	int k;
	long long n, i, result, x, y, z, temp;
	scanf("%d", &k);
	n = Power(2, k);
	printf("%lld\n", fact(k));
	for(i = 1; i <= n; i++)
	{
		if(i < (n / 2))
		{
			result = 0;
			printf("%lld\n", result);
		}
		else
		{
			//result = (fact(i - 1) / fact(i - n / 2));
			result = (fact(i - 1) * fact(n / 2)) % MOD;
			result = (result * n) % MOD;
			result = result / fact(i - n / 2);
			//result = (n * ((((fact(i - 1) / fact(i - n / 2)) % MOD) * fact(n / 2)) % MOD)) % MOD;
			printf("%lld\n", result);
		}
	}
	return 0;
}
 
long long fact(long long n)
{
	long long x;
	if(n == 1 || n == 0)
	{
		x = 1;
	}
	else
	{
		x = (n * fact(n - 1) % MOD);
	}
	return x;
}
 
long long Power(int a, int b)
{	
	if (b==0)
		return 1;
	if (b%2==0)
	{
		return Power(a*a, b/2);
	}
	else if (b%2==1)
	{
		return a*Power(a*a,b/2);
	}
} 

#include <stdio.h>
#define MOD 1000000009

int main()
{
	long long x, y, z;
	scanf("%lld %lld", &x, &y);
	z = (x * y) % MOD;
	printf("%lld\n", z);
	return 0;
}

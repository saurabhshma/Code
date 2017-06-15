//http://practice.geeksforgeeks.org/problems/ncr/0

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int NCR[1001][801];

long long int nCr(int n, int r)
{
	if(NCR[n][r] == -1)
	{
		if(r == 1)
			NCR[n][r] = n % MOD;
		else if(n == r)
			NCR[n][r] = 1 % MOD;
		else if(n < r)
			NCR[n][r] = 0 % MOD;
		else
			NCR[n][r] = ((nCr(n - 1, r - 1) % MOD) + (nCr(n - 1, r) % MOD)) % MOD;
	}
	return NCR[n][r];
}

int main()
{
	int t, n, r;
	long long int result;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n >> r;
		for(int j = 0; j <= n; j++)
			for(int k = 0; k <= r; k++)
				NCR[j][k] = -1;
		result = nCr(n, r);
		cout << result << "\n";
	}	
	return 0;
}
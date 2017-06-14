//	http://practice.geeksforgeeks.org/problems/nth-fibonacci-number/0

#include <bits/stdc++.h>
#define MAX_SIZE 1001
#define mod 1000000007
using namespace std;

long long int A[MAX_SIZE];

long long int fib(int n)
{
	if(A[n] == -1)
	{
		if(n == 0 || n == 1)
			A[n] = n % mod;
		else
			A[n] = (fib(n - 1) % mod + fib(n - 2) % mod) % mod;
	}
	return(A[n]);
}

int main()
{
	int t, n;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n;
		for(int j = 0; j <= n; j++)
			A[j] = -1;
		long long int result = fib(n);
		cout << result << "\n";
	}
	return 0;
}
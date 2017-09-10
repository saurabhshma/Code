//http://practice.geeksforgeeks.org/problems/chocolate-distribution-problem/0
#include <bits/stdc++.h>

using namespace std;

int chocolateDistribution(int A[], int n, int m)
{
	sort(A, A + n);
	int min = INT_MAX;
	for(int i = 0; i <= n - m; i++)
	{
		if(A[i + m - 1] - A[i] < min)
			min = A[i + m - 1] - A[i];
	}
	return min;
}

int main()
{
	int t, n, m;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n;
		int A[n];
		for(int j = 0; j < n; j++)
			cin >> A[j];
		cin >> m;
		int result = chocolateDistribution(A, n, m);
		cout << result << "\n";
	}
	return 0;
}
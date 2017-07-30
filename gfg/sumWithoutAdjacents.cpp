//http://practice.geeksforgeeks.org/problems/max-sum-without-adjacents/0
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, n, maxSum;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		maxSum = 0;
		cin >> n;
		int A[n];
		for(int j = 0; j < n; j++)
		{
			cin >> A[j];
		}

		if(n == 1)
			cout << A[0] << "\n";
		else
		{
			int incl = A[0];
			int excl = 0;
			for(int j = 1; j < n; j++)
			{
				int tempIncl = A[j] + excl;
				int tempExcl = max(incl, excl);
				incl = tempIncl;
				excl = tempExcl;
			}
			cout << max(incl, excl) << "\n";
		}
	}
	return 0;
}
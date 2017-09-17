//http://practice.geeksforgeeks.org/problems/egg-dropping-puzzle/0
#include <bits/stdc++.h>

using namespace std;

int findMinTrials(int n, int k)
{
	int A[n + 1][k + 1];
	for(int i = 0; i <= k; i++)
		A[1][i] = i;
	for(int i = 1; i <= n; i++)
	{	
		A[i][1] = 1;
		A[i][0] = 0;
	}
	for(int i = 2; i <= n; i++)
	{
		for(int j = 2; j <= k; j++)
		{
			A[i][j] = INT_MAX;
			for(int x = 1; x <= j; x++)
			{
				int temp = 1 + max(A[i - 1][x - 1], A[i][j - x]);
				A[i][j] = min(temp, A[i][j]);
			}		
		}
	}
	return A[n][k];
}

int main()
{
	int t, k, n;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n >> k;
		int result = findMinTrials(n, k);
		cout << result << "\n";
	}
	return 0;
}
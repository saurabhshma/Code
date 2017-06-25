//http://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0

#include <bits/stdc++.h>

using namespace std;

int lis[1001];

int LIS(int A[], int n)
{
	if(lis[n] == -1)
	{
		if(n == 1)
			lis[n] = 1;
		else
		{
			int max = 1, temp;
			for(int i = n - 2; i >= 0; i--)
			{
				if(A[i] < A[n - 1])
				{
					temp = LIS(A, i + 1);
					if((1 + temp) > max)
						max = 1 + temp;
				}
			}
			lis[n] = max; 
		}
	}
	return lis[n];
}

int main()
{
	int t, n, temp;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n;
		int A[n];
		for(int j = 0; j < n; j++)
			cin >> A[j];
		for(int j = 0; j <= n; j++)
			lis[j] = -1;
		for(int j = 1; j <= n; j++)
			lis[j] = LIS(A, j);
		cout << *max_element(lis, lis + n + 1) << "\n";
	}
	return 0;
}
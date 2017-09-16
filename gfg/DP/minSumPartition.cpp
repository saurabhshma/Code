//http://practice.geeksforgeeks.org/problems/minimum-sum-partition/0
#include <bits/stdc++.h>

using namespace std;

int createSubsetSumTable(int A[], int n, int sum, vector< vector<int> >& table)
{
	if(sum == 0)
		return 1;
	if(n <= 0 || sum < 0)
		return 0;
	if(table[n][sum] == -1)
	{
		table[n][sum] = createSubsetSumTable(A, n - 1, sum - A[n - 1], table) || createSubsetSumTable(A, n - 1, sum, table);
	}
	return table[n][sum];
}


int main()
{
	int t, n;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n;
		int sum = 0;
		int A[n];
		for(int j = 0; j < n; j++)
		{
			cin >> A[j];
			sum += A[j];
		}
		vector< vector<int> > table(n + 1, vector<int>(sum + 1));
		for(int j = 0; j <= n; j++)
		{
			for(int k = 0; k <= sum; k++)
			{
				table[j][k] = -1;
			}
		}
		int j;
		for(j = sum / 2; j > 0; j--)
		{
			int temp = createSubsetSumTable(A, n, j, table);
			// cout << temp << "\n";
			if(temp == 1)
				break;
		}
		// cout << "j:, sum: " << j << " " << sum << "\n";
		cout << abs((sum - j) - j) << "\n";
	}
	return 0;
}
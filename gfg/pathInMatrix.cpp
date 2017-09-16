//http://practice.geeksforgeeks.org/problems/path-in-matrix/0
#include <bits/stdc++.h>

using namespace std;

int table[20][20];

int findMaxPath(vector< vector<int> >& input, int i, int j, int n)
{
	if(i == n)
		return 0;
	else if(j < 0 || j == n)
		return 0;
	if(table[i][j] == -1)
	{
		table[i][j] = input[i][j] + max(findMaxPath(input, i + 1, j - 1, n), max(findMaxPath(input, i + 1, j, n), findMaxPath(input, i + 1, j + 1, n)));
	}
	return table[i][j];
}

int main()
{
	int t, n;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n;
		vector< vector<int> > input(n, vector<int>(n));
		for(int j = 0; j < n; j++)
		{
			for(int k = 0; k < n; k++)
			{
				cin >> input[j][k];
			}
		}
		for(int j = 0; j < n; j++)
		{
			for(int k = 0; k < n; k++)
			{
				table[j][k] = -1;
			}
		}
		int maxResult = INT_MIN;
		for(int j = 0; j < n; j++)
		{
			int temp = findMaxPath(input, 0, j, n);
			maxResult = max(maxResult, temp);
		}
		cout << maxResult << "\n";
	}
	return 0;
}
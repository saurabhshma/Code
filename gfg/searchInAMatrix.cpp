#include <bits/stdc++.h>

using namespace std;

int searchMatrix(vector< vector<int> > input, int n, int m, int x)
{
	int i = 0, j = m - 1;
	while(1)
	{
		if(j < 0 || i > n - 1)
			return 0;
		if(input[i][j] == x)
			return 1;
		else if(input[i][j] > x)
			j--;
		else
			i++;
	}
}

int main()
{
	int t, m, n, x;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n >> m;
		vector< vector<int> > input(n, vector<int>(m));
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				cin >> input[i][j];
			}
		}
		cin >> x;
		int result = searchMatrix(input, n, m, x);
		cout << result << "\n";
	}
	return 0;
}
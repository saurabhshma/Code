//http://www.geeksforgeeks.org/dynamic-programming-set-6-min-cost-path/
#include <bits/stdc++.h>

using namespace std;

int minCost[101][101];

typedef vector<vector<int> > int2d; 

int minCostPath(int m, int n, int row, int col, int2d& A)
{
	if(minCost[m][n] == -1)
	{
		if(m < 0 || n < 0)
			return INT_MAX;
		else if((m == 0 && n == 1) || (m == 1 && n == 0) || (m == 1 && n == 1))
			minCost[m][n] = A[0][0] + A[m][n];
		else
			minCost[m][n] = min(min(minCostPath(m - 1, n - 1, row, col, A), minCostPath(m - 1, n, row, col, A)), minCostPath(m, n - 1, row, col, A)) + A[m][n];
	}
	return (minCost[m][n]);
}

int main()
{
	int t, row, col, m, n;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> row >> col;
		int2d A(row, vector<int>(col)); 
		for(int j = 0; j < row; j++)
			for(int k = 0; k < col; k++)
				cin >> A[j][k];
		cin >> m >> n;
		for(int j = 0; j < row; j++)
			for(int k = 0; k < col; k++)
				minCost[j][k] = -1;
		minCost[0][0] = A[0][0];
		int result = minCostPath(m, n, row, col, A);
		cout << result << "\n";
	}
	return 0;
}
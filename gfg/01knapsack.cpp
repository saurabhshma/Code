//http://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0
#include <bits/stdc++.h>

using namespace std;

int table[101][101];

int knapsack(int val[], int weights[], int w, int n)
{
	//1cout << "w: " << w << " n: " << n << "\n";
	if(w < 0)
		return INT_MIN;

	if(table[n][w] == -1)
	{
		if(n == 0)
			table[n][w] = 0;
		else	
			table[n][w] = max(val[n - 1] + knapsack(val, weights, w - weights[n - 1], n - 1), knapsack(val, weights, w, n - 1));
	}
	return (table[n][w]);
}

int main()
{
	int t, n, w;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n;
		cin >> w;
		int val[n], weights[n];
		for(int j = 0; j < n; j++)
		{
			cin >> val[j];
		}
		for(int j = 0; j < n; j++)
		{
			cin >> weights[j];
		}
		for(int j = 0; j <= n; j++)
			for(int k = 0; k <= max(w, *max_element(weights, weights + n)); k++)
				table[j][k] = -1;
		int result = knapsack(val, weights, w, n);
		// for(int j = 0; j <= n; j++)
		// {
		// 	for(int k = 0; k <= max(w, *max_element(weights, weights + n)); k++)
		// 	{
		// 		cout << table[j][k] << " ";
		// 	}
		// 	cout << "\n";
		// }

		cout << result << "\n";
	}
	return 0;
}
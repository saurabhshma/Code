//http://practice.geeksforgeeks.org/problems/relative-sorting/0

#include <bits/stdc++.h>

using namespace std;

void relativeSorting(int A[], int B[], int m, int n)
{
	map<int, int> table;
	for(int i = 0; i < m; i++)
	{
		if(table.find(A[i]) == table.end())
			table[A[i]] = 1;
		else
			table[A[i]]++;
	}
	for(int i = 0; i < n; i++)
	{
		if(table.find(B[i]) == table.end())
		{
			//do nothing
		}
		else
		{
			for(int j = 0; j < table[B[i]]; j++)
				cout << B[i] << " ";
			table.erase(B[i]);
		}
	}
	for(map<int, int>::iterator it = table.begin(); it != table.end(); it++)
	{
		for(int i = 0; i < it->second; i++)
			cout << it->first << " ";
	}
	cout << "\n";
}

int main()
{
	int t, m, n;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> m >> n;
		int A[m], B[n];
		for(int j = 0; j < m; j++)
			cin >> A[j];
		for(int j = 0; j < n; j++)
			cin >> B[j];
		relativeSorting(A, B, m, n);
	}
	return 0;
}
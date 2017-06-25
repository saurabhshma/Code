//http://practice.geeksforgeeks.org/problems/leaders-in-an-array/0
#include <bits/stdc++.h>

using namespace std;

void leaders(int A[], int n)
{
	int max = A[n - 1];
	vector<int> result;
	result.push_back(max);
	for(int i = n - 2; i >= 0; i--)
	{
		if(A[i] > max)
		{
			max = A[i];
			result.push_back(max);
		}
	}
	for(int i = result.size() - 1; i >= 0; i--)
		cout << result[i] << " ";
	cout << "\n";	
}

int main()
{
	int t, n;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n;
		int A[n];
		for(int j = 0; j < n; j++)
			cin >> A[j];
		leaders(A, n);
	}
	return 0;
}
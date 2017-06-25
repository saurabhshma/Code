//http://practice.geeksforgeeks.org/problems/rotate-array-by-n-elements/0
#include <bits/stdc++.h>

using namespace std;

void rotate(int A[], int n, int d)
{
	int temp[d];
	for(int i = 0; i < d; i++)
		temp[i] = A[i];
	for(int i = d, j = 0; i < n; i++, j++)
		A[j] = A[i];
	for(int i = n - d, j = 0; i < n; i++, j++)
		A[i] = temp[j];
	for(int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << "\n";
}

int main()
{
	int t, n, d;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n >> d;
		int A[n];
		for(int j = 0; j < n; j++)
			cin >> A[j];
		rotate(A, n, d);
	}
	return 0;
}
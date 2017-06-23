//http://practice.geeksforgeeks.org/problems/reverse-an-array/0
#include <bits/stdc++.h>

using namespace std;

void reverse(int A[], int n)
{
	int temp;
	for(int i = 0; i < n / 2; i++)
	{
		temp = A[i];
		A[i] = A[n - 1 - i];
		A[n - 1 - i] = temp;
	}
	for(int i = 0; i < n; i++)
		cout << A[i] << " ";
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
		reverse(A, n);
	}
	return 0;
}
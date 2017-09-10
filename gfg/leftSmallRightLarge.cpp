//http://practice.geeksforgeeks.org/problems/unsorted-array/0
#include <bits/stdc++.h>

using namespace std;

int findPivot(int A[], int n)
{
	int max = 0, pivot = -1;
	for(int i = 1; i < n; i++)
	{
		if(pivot == -1)
		{
			if(A[i] >= A[max])
			{
				pivot = i;
				max = i;
			}
		}
		else
		{
			if(A[i] >= A[pivot])
			{
				max = i;
			}
			else
			{
				pivot = -1;
			}
		}
	}
	if(pivot == n - 1 || pivot == 0 || pivot == -1)
		return -1;
	else
		return A[pivot];
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
		{
			cin >> A[j];
		}
		int result = findPivot(A, n);
		cout << result << "\n";
	}
	return 0;
}
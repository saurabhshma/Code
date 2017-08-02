//http://practice.geeksforgeeks.org/problems/kth-smallest-element/0

#include <bits/stdc++.h>

using namespace std;

int partition(int A[], int low, int high)
{
	int x = A[high];
	int i = low - 1;
	for(int j = low; j < high; j++)
	{
		if(A[j] < x)
		{
			i = i + 1;
			swap(A[i], A[j]);
		}
	}
	swap(A[i + 1], A[high]);
	return (i + 1);
}

int kthSmallesElement(int A[], int low, int high, int k)
{
	int pivot = partition(A, low, high);
	if(pivot == k - 1)
		return A[pivot];
	else if(pivot < k - 1)
		kthSmallesElement(A, pivot + 1, high, k);
	else
		kthSmallesElement(A, low, pivot - 1, k);
}

int main()
{
	int t, n, k;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n;
		int A[n];
		for(int j = 0; j < n; j++)
			cin >> A[j];
		cin >> k;
		int result = kthSmallesElement(A, 0, n - 1, k);
		cout << result << "\n";
	}
	return 0;
}
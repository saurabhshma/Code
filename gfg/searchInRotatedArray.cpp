//http://practice.geeksforgeeks.org/problems/search-in-a-rotated-array/0
#include <bits/stdc++.h>

using namespace std;

int binSearch(int A[], int k, int low, int high)
{
	if(low > high)
		return -1;
	int mid = (low + high) / 2;
	if(A[mid] == k)
		return mid;
	else if(A[mid] > k)
		binSearch(A, k, low, mid - 1);
	else
		binSearch(A, k, mid + 1, high);
}

int findPivot(int A[], int low, int high, int n)
{
	if(low > high || ((high == (n - 1)) && (low == (n - 1))))
		return -1;
	int mid = (low + high) / 2;
	if(A[mid] > A[mid + 1])
		return mid;
	else if(A[mid] >= A[0])
		findPivot(A, mid + 1, high, n);
	else
		findPivot(A, low, mid - 1, n);
}

int search(int A[], int k, int n)
{
	int result;
	int p = findPivot(A, 0, n - 1, n);
	//cout << "pivot : " << p << "\n";
	if(p == -1)
		result = binSearch(A, k, 0, n - 1);
	else if(k < A[0])
		result = binSearch(A, k, p + 1, n - 1);
	else
		result = binSearch(A, k, 0, p);
	return result;
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
		int result = search(A, k, n);
		cout << result << "\n";
	}
	return 0;
}
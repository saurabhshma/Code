//http://practice.geeksforgeeks.org/problems/k-largest-elements/0
#include <bits/stdc++.h>

using namespace std;

void kLargestElement(int A[], int n, int k)
{
	vector<int> heap(A, A + n);
	make_heap(heap.begin(), heap.end());
	for(int i = 0; i < k; i++)
		pop_heap(heap.begin(), heap.end() - i);
	for(int i = heap.size() - 1; i > heap.size() - k - 1; i--)
		cout << heap[i] << " ";
	cout << "\n";
}

int main()
{
	int t, n, k;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n >> k;
		int A[n];
		for(int j = 0; j < n; j++)
			cin >> A[j];
		kLargestElement(A, n, k);
	}
	return 0;
}
//http://practice.geeksforgeeks.org/problems/kth-largest-element-in-a-stream/0
#include <bits/stdc++.h>

using namespace std;

void printKthLargest(int A[], int n, int k)
{
	priority_queue <int, vector<int>, greater<int> > minHeap;
	for(int i = 0; i < k - 1; i++)
	{
		minHeap.push(A[i]);
		cout << -1 << " ";
	}
	if(k - 1 < n)
		minHeap.push(A[k - 1]);
	cout << minHeap.top() << " ";
	for(int i = k; i < n; i++)
	{
		if(A[i] > minHeap.top());
		{
			minHeap.pop();
			minHeap.push(A[i]);
		}
		cout << minHeap.top() << " ";
	}
	cout << "\n";
}

int main()
{
	int t, k, n;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> k >> n;
		int A[n];
		for(int j = 0; j < n; j++)
		{
			cin >> A[j];
		}
		printKthLargest(A, n, k);
	}
	return 0;
}
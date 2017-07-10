//http://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram/0
#include <bits/stdc++.h>

using namespace std;

int findMaxArea(int A[], int start, int n)
{
	int maxArea = A[start];
	int min = A[start];
	//cout << "A[start]: " << A[0] << "\n"; 
	for(int i = start + 1; i < n; i++)
	{
		//cout << "maxArea: " << maxArea << "\n";
		if(A[i] < min)
			min = A[i];
		int temp = min * (i - start + 1);
		if(temp > maxArea)
			maxArea = temp;
	}
	return maxArea;
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
		int max = INT_MIN;
		for(int j = 0; j < n; j++)
		{
			int result = findMaxArea(A, j, n);
			//cout << "result: " << result << "\n";
			if(result > max)
				max = result;
		}
		cout << max << "\n";
	}
	return 0;
}
//http://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
#include <bits/stdc++.h>

using namespace std;

int kadane(int A[], int n)
{
	int currentSum = 0, maxSum = 0;
	for(int i = 0; i < n; i++)
	{
		if((A[i] < 0) && (currentSum == 0))
		{
			//do nothing
		}
		else
		{
			currentSum += A[i];
			if(currentSum <= 0)
				currentSum = 0;
			else
				if(currentSum > maxSum)
					maxSum = currentSum;
		}
	}
	int temp = INT_MIN;
	bool flag = false;
	if(currentSum == 0)
	{
		for(int i = 0; i < n; i++)
		{
			if(A[i] >= 0)
			{
				flag = false;
				break;
			}
			else
			{
				flag = true;
				if(A[i] > temp)
					temp = A[i];
			}
		}
	}
	if(flag == false)
		return maxSum;
	else
		return temp;
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
		int result = kadane(A, n);
		cout << result << "\n";
	}
	return 0;
}
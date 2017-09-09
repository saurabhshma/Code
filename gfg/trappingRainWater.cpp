//http://practice.geeksforgeeks.org/problems/trapping-rain-water/0
#include <bits/stdc++.h>

using namespace std;

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
		int start = 0;
		for(int j = 1; j < n; j++)
		{
			if(A[j] >= A[start])
			{
				start++;
			}
			else
			{
				break;
			}
		}
		int end = n - 1;
		for(int j = n - 2; j > 0; j--)
		{
			if(A[j] >= A[end])
			{
				end--;
			}
			else
			{
				break;
			}
		}
		stack<int> temp;
		int max = A[start];
		int sum = 0;
		for(int j = start + 1; j <= end; j++)
		{
			// cout << A[j] << " " << " sum " << sum << "\n";
			if(A[j] < max)
				temp.push(A[j]);
			else
			{
				while(!temp.empty())
				{	
					sum += max - temp.top();
					temp.pop();
				}
				max = A[j];
			}
		}
		// cout << sum << "\n";
		while(!temp.empty())
		{
			max = temp.top();
			temp.pop();
			if(temp.empty())
				break;
			else
			{
				while(temp.top() < max)
				{
					sum += max - temp.top();
					temp.pop();
				}
				if(temp.empty())
					break;
			}
		}
		cout << sum << "\n";
	}
	return 0;
}
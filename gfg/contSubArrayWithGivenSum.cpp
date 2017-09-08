//http://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, n, s;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n >> s;
		int A[n];
		for(int j = 0; j < n; j++)
			cin >> A[j];
		int start = 0, end = -1, sum = 0;
		for(int j = 0; j < n; j++)
		{
			sum += A[j];
			if(sum == s)
			{
				end = j;
				break;
			}
			else if(sum < s)
			{
				//do nothing;
			}
			else
			{
				while(sum > s)
				{
					sum -= A[start];
					start++;
				}
				if(sum == s)
				{
					end = j;
					break;
				}
			}
			if(j == n - 1)
			{
				while(start < n)
				{
					sum -= A[start];
					start++;
					if(sum == s)
					{
						end = j;
						break;
					}
				}
			}
		}
		if(end == -1)
			cout << -1 << "\n";
		else
			cout << start + 1 << " " << end + 1 << "\n";
	}
	return 0;
}
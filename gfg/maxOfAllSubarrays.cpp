//http://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0
#include <bits/stdc++.h>

using namespace std;

void maxOfAllSubarrays(int A[], int n, int k)
{
	deque< pair<int, int> > maxDeque;
	maxDeque.push_back(make_pair(A[0], 0));
	for(int i = 1; i < k - 1; i++)
	{
		if(A[i] < (maxDeque.back()).first)
		{
			maxDeque.push_back(make_pair(A[i], i));
		}
		else
		{
			while((maxDeque.back()).first <= A[i])
			{
				maxDeque.pop_back();
				if(maxDeque.empty())
						break;
			}
			maxDeque.push_back(make_pair(A[i], i));
		}
	}
	for(int i = k - 1; i < n; i++)
	{
		if((i - (maxDeque.front()).second) <= k - 1)
		{
			if(A[i] < (maxDeque.back()).first)
			{
				maxDeque.push_back(make_pair(A[i], i));
			}
			else
			{
				//cout << (maxDeque.back()).first << "\n";
				while((maxDeque.back()).first <= A[i])
				{
					//cout << "yo\n";
					maxDeque.pop_back();
					if(maxDeque.empty())
						break;
				}
				maxDeque.push_back(make_pair(A[i], i));
			}
		}
		else
		{
			maxDeque.pop_front();
			if(A[i] < (maxDeque.back()).first)
			{
				maxDeque.push_back(make_pair(A[i], i));
			}
			else
			{
				while((maxDeque.back()).first <= A[i])
				{
					maxDeque.pop_back();
					if(maxDeque.empty())
						break;
				}
				maxDeque.push_back(make_pair(A[i], i));
			}
		}
		cout << (maxDeque.front()).first << " ";
	}
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
		{
			cin >> A[j];
		}
		if(k == 1)
		for(int j = 0; j < n; j++)
			cout << A[j] << " ";
		else
			maxOfAllSubarrays(A, n, k);
		cout << "\n";
	}
	return 0;
}
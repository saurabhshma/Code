//http://practice.geeksforgeeks.org/problems/next-larger-element/0
#include <bits/stdc++.h>

using namespace std;

void nextGreaterElement(int A[], int n)
{
	vector<int> s;
	map<int, int> nextGreater;
	s.push_back(A[0]);
	for(int i = 1; i < n; i++)
	{
		int next = A[i];
		while(1)
		{
			if(s.empty())
			{
				s.push_back(next);
				break;
			}
			else if(next > s.back())
			{
				nextGreater[s.back()] = next;
				s.pop_back();
			}
			else
			{
				s.push_back(next);
				break;
			}
		}
		
	}
	while(!s.empty())
	{
		nextGreater[s.back()] = -1;
		s.pop_back();
	}
	for(int i = 0; i < n; i++)
	{
		cout << nextGreater[A[i]] << " ";
	}
	cout << "\n";
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
		nextGreaterElement(A, n);
	}
	return 0;
}
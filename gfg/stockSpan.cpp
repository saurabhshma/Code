//http://practice.geeksforgeeks.org/problems/stock-span-problem/0

#include <bits/stdc++.h>

using namespace std;

void stockSpan(int A[], int n)
{
	deque<int> table;
	int result[n];
	int tempSize;
	int index = -1;
	for(int i = n - 1; i >= 0; i--)
	{
		//cout << "yo\n";
		if(table.empty())
		{
			table.push_back(A[i]);
			index = i - 1;
		}
		//cout << "Table size: " << table.size() <<"\n";
		if(table.front() == A[i])
		{
			int j;
			for(j = index; j >= 0; j--)
			{
				if(A[j] <= table.back())
					table.push_back(A[j]);
				else
				{ 
					break;
				}
			}
			index = j;
		}
		//cout << "index: " << index << "\n";
		tempSize = table.size();
		//cout << "tempSize: " << tempSize << "\n";
		for(int j = index; j >= 0; j--)
		{
			if(A[j] <= A[i])
				tempSize++;
			else
				break;
		}	
		table.pop_front();
		result[i] = tempSize;
	}
	for(int i = 0; i <= n -1; i++)
		cout << result[i] << " ";
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
		stockSpan(A, n);
	}
	return 0;
}
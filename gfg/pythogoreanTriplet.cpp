//http://www.geeksforgeeks.org/find-pythagorean-triplet-in-an-unsorted-array/
#include <bits/stdc++.h>

using namespace std;

bool pythogoreanTriplet(int A[], int n)
{
	map<int, bool> table;
	bool flag = false;
	for(int i = 0; i < n; i++)
	{
		table[(A[i]) * (A[i])] = true;
	}
	for(int i = 0; i < n; i++)
	{
		int temp = A[i] *A[i];
		for(int j = i + 1; j < n; j++)
		{
			if(table.find(temp + (A[j] * A[j])) == table.end())
			{}
			else
			{
				flag = true;
				break;
			}
		}
		if(flag)
			break;
	}
	return flag;
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
		{
			cin >> A[j];
		}
		bool result = pythogoreanTriplet(A, n);
		if(result)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}
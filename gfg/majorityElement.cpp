//http://practice.geeksforgeeks.org/problems/majority-element/0

#include <bits/stdc++.h>

using namespace std;

int majorityElement(int A[], int n)
{
	map<int, int> count;
	for(int i = 0; i < n; i++)
	{
		if(count.find(A[i]) == count.end())
			count[A[i]] = 1;
		else
			count[A[i]]++ ;
	}
	
	for(int i = 0; i < n; i++)
	{
		if(count[A[i]] > (n / 2))
			return (A[i]);
	}
	return -1;
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
		int result = majorityElement(A, n);
		if(result == -1)
			cout << "NO Majority Element\n";
		else
			cout << result << "\n";
	}
	return 0;
}
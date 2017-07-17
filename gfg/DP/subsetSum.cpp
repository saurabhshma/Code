//http://practice.geeksforgeeks.org/problems/subset-sum-problem/0
#include <bits/stdc++.h>

using namespace std;

bool subsetSum(int A[], int n, int sum)
{
	if(sum < 0)
		return false;
	if(sum == 0)
		return true;
	if(n < 0)
		return false;
	else
		return (subsetSum(A, n - 1, sum - A[n]) || subsetSum(A, n - 1, sum));
}

int main()
{
	int t, n;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n;
		int A[n], sum = 0;
		for(int j = 0; j < n; j++)
			cin >> A[j];
		for(int j = 0; j < n; j++)
			sum	+= A[j];
		bool result;
		if(sum % 2 != 0)
			result = false;
		else
			result = subsetSum(A, n - 1, sum / 2);
		if(result == false)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
	return 0;
}
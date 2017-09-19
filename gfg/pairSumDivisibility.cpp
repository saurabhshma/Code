//http://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem/0
#include <bits/stdc++.h>

using namespace std;

bool pairSumDivisibility(int A[], int n, int k)
{
	int countRemainder[k];
	for(int i = 0; i < k; i++)
		countRemainder[i] = 0;
	for(int i = 0; i < n; i++)
		countRemainder[A[i] % k]++;
	bool flag = true;
	if(countRemainder[0] % 2 != 0)
	{
		flag = false;
		return flag;
	}
	else
	{
		for(int i = 1; i < k/2; i++)
		{
			if(countRemainder[i] != (countRemainder[k - i]))
			{
				flag = false;
				return flag;
			}
		}
	}
	if(k % 2 == 0)
	{
		if(countRemainder[k / 2] % 2 != 0)
		{
			flag = false;
			return flag;
		}
	}
	else
	{
		if(countRemainder[k / 2] != countRemainder[k - k / 2])
		{
			flag = false;
			return flag;
		}
	}
	return flag;
}

int main()
{
	int t, n, k;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n;
		int A[n];
		for(int j = 0; j < n; j++)
		{
			cin >> A[j];
		}
		cin >> k;
		if(n % 2 != 0)
			cout << "False\n";
		else
		{
			if(k == 1)
				cout << "True\n";
			else
			{
				bool result = pairSumDivisibility(A, n, k);
				if(result)
					cout << "True\n";
				else
					cout << "False\n";
			}
		}
	}
	return 0;
}
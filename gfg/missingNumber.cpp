//http://practice.geeksforgeeks.org/problems/missing-number-in-array/0

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, n;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n;
		int totalSum = (n * (n + 1)) / 2;
		int sum = 0;
		int temp;
		for(int j = 0; j < n - 1; j++)
		{
			cin >> temp;
			sum += temp; 
		}
		cout << (totalSum - sum) << "\n";
	}
	return 0;
}
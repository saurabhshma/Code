#include <bits/stdc++.h>

using namespace std;

int LIS(vector<int> &A, int n)
{
	vector<int> lis(n, -1);
	if(n == 1)
	{
		if(lis[n - 1] == -1)
			lis[n - 1] = 1;
		return lis[n - 1];
	}
	else
	{
		int max = 1;
		for(int i = n - 2; i >= 0; i--)
		{
			int temp;
			if(A[i] < A[n - 1])
			{
				if(lis[i] == -1)
					lis[i] = LIS(A, i + 1);
				if((temp = 1 + lis[i]) > max)
					max = temp;
			}
		}
		lis[n - 1] = max;
		return lis[n - 1];
	}
}

int main()
{
	int t, n, temp;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n;
		vector<int>A(n);
		//vector<int>lis(n - 1, -1);
		for(int j = 0; j < n; j++)
		{
			cin >> temp; 
			A[j] = temp;
		}
		cout << LIS(A, n) << "\n";
	}
	return 0;
}
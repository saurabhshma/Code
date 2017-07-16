//http://practice.geeksforgeeks.org/problems/cutted-segments/0
#include <bits/stdc++.h>

using namespace std;

int table[4001];

int cutSegments(int n, int x, int y, int z)
{
	if(n == 0)
		return 0;
	if(n < 0)
		return -1;
	if(table[n] == -1)
	{
		int a = 1 + cutSegments(n - x, x, y, z);
		int b = 1 + cutSegments(n - y, x, y, z);
		int c = 1 + cutSegments(n - z, x, y, z);
		if(a <= 0 && b <= 0 && c <= 0)
			table[n] = INT_MIN;
		else
			table[n] = max(max(a, b), c);
	}
	return table[n];
}

int main()
{
	int t, n, x, y, z;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n;
		cin >> x >> y >> z;
		for(int j = 0; j <= n; j++)
			table[j] = -1;
		int result = cutSegments(n, x, y, z);
		cout << result << "\n";
	}
	return 0;
}
//http://practice.geeksforgeeks.org/problems/thief-try-to-excape/0

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, n, x, y, temp; 
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> x >> y >> n;
		int H[n], numJumps = 0;
		for(int j = 0; j < n; j++)
			cin >> H[j];
		for(int j = 0; j < n; j++)
		{
			temp = H[j] / (x - y);
			if(x < H[j])
			{
				while((temp - 1) * (x - y) + x  >= H[j])
				{
					temp--;
				}
				numJumps += temp + 1;
			}
			else
				numJumps += 1;
			// cout << H[j] << " "  << numJumps << "\n";
		}
		cout << numJumps << "\n";
	}
	return 0;
}
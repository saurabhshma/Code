//http://practice.geeksforgeeks.org/problems/edit-distance/0
#include <bits/stdc++.h>

using namespace std;

int ED[101][101];

int ed(string& s1, string& s2, int n1, int n2)
{
	if(ED[n1][n2] == -1)
	{
		if(n1 == 0)
			ED[n1][n2] = n2;
		else if(n2 == 0)
			ED[n1][n2] = n1;
		else
		{
			if(s1[n1 - 1] == s2[n2 - 1])
				ED[n1][n2] = ed(s1, s2, n1 - 1, n2 - 1);
			else
			{
					ED[n1][n2] = min(min(1 + ed(s1, s2, n1, n2 - 1), 1 + ed(s1, s2, n1 - 1, n2 - 1)), 1 + ed(s1, s2, n1 - 1, n2));
			}
		}
	}
	return ED[n1][n2];
}

int main()
{
	int t, n1, n2;
	string s1, s2;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n1 >> n2;
		cin >> s1;
		cin >> s2;
		for(int j = 0; j <= n1; j++)
			for(int k = 0; k <= n2; k++)
				ED[j][k] = -1;
		int result = ed(s1, s2, n1, n2);
		cout << result << "\n";
	}
	return 0;
}
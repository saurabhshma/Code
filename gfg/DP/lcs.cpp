//http://practice.geeksforgeeks.org/problems/longest-common-subsequence/0
#include <bits/stdc++.h>

using namespace std;

int LCS[101][101];

int lcs(string& s1, string& s2, int n1, int n2)
{
	if(LCS[n1][n2] == -1)
	{
		if((n1 == 0) || (n2 == 0))
			LCS[n1][n2] = 0;
		else
		{
			if(s1[n1 - 1] == s2[n2 - 1])
				LCS[n1][n2] = 1 + lcs(s1, s2, n1 - 1, n2 - 1);
			else
			{
				int a = lcs(s1, s2, n1 - 1, n2);
				int b = lcs(s1, s2, n1, n2 - 1);
				LCS[n1][n2] = max(a, b);
			}
		}
	}
	return LCS[n1][n2];
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
				LCS[j][k] = -1;
		int result = lcs(s1, s2, n1, n2);
		cout << result << "\n";
	}
	return 0;
}
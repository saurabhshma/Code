//http://practice.geeksforgeeks.org/problems/bo`olean-parenthesization/0

#include <bits/stdc++.h>
#define MOD 1003

using namespace std;

pair<long long int, long long int> numOfP(vector< vector <pair<long long int, long long int> > >& table, string input, int start, int end)
{
	if((table[start][end]).first == -1 && (table[start][end]).second == -1)
	{
		if(end - start == 0)
		{
			if(input[start] == 'T')
				table[start][end] = make_pair(1, 0);
			else
				table[start][end] = make_pair(0, 1);
		}
		else
		{
			pair<long long int, long long int> sum = make_pair(0, 0);
			for(int i = start + 2; i <= end; i = i + 2)
			{
				pair<long long int, long long int> left = numOfP(table, input, start, i - 2);
				pair<long long int, long long int> right = numOfP(table, input, i, end);
				long long int tt = left.first * right.first;
				long long int tf = left.first * right.second;
				long long int ft = left.second * right.first;
				long long int ff = left.second * right.second;
				if(input[i - 1] == '&')
				{
					sum.first += tt;
					sum.second += tf + ft + ff;
				}
				else if(input[i - 1] == '|')
				{
					sum.first += tt + tf + ft;
					sum.second += ff;	
				}
				else
				{
					sum.first += tf + ft;
					sum.second += ff + tt;
				}
			}
			table[start][end] = sum;
		}
	}
	return (table[start][end]);
}

int main()
{
	int t, n;
	string input;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n;
		cin >> input;
		vector< vector <pair<long long int, long long int> > > table(n, vector< pair<long long int, long long int> > (n));
		for(int j = 0; j < n; j++)
		{
			for(int k = 0; k < n; k++)
			{
				table[j][k] = make_pair(-1, -1);
			}
		}
		pair<long long int, long long int> result = numOfP(table, input, 0, n - 1);
		cout << result.first % MOD << "\n";
	}
	return 0;
}
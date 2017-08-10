//http://practice.geeksforgeeks.org/problems/is-binary-number-multiple-of-3/0
#include <bits/stdc++.h>

using namespace std;

bool isBinary3Multiple(string input)
{
	vector< vector<int> > table(3, vector<int>(2));
	table[0][0] = 0;
	table[0][1] = 1;
	table[1][0] = 2;
	table[1][1] = 0;
	table[2][0] = 1;
	table[2][1] = 2;
	int state = 0;
	for(int i = 0; i < input.length(); i++)
	{
		if(input[i] == '0')
			state = table[state][0];
		else
			state = table[state][1];
	}
	if(state == 0)
		return true;
	else
		return false;
}

int main()
{
	int t;
	string input;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> input;
		bool result = isBinary3Multiple(input);
		if(result)
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
	}
	return 0;
}
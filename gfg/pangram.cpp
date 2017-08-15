//http://practice.geeksforgeeks.org/problems/pangram-strings/0
#include <bits/stdc++.h>

using namespace std;

bool checkPangram(string input)
{
	vector<bool> checkArr(26, false);
	if(input.size() < 26)
		return false;
	for(int i = 0; i < input.size(); i++)
	{
		if(input[i] >= 'a' && input[i] <= 'z')
		{
			checkArr[input[i] - 'a'] = true;
		}
		else if(input[i] >= 'A' && input[i] <= 'Z')
		{
			checkArr[input[i] - 'A'] = true;
		}
	}
	for(int i = 0; i < 26; i++)
	{
		if(checkArr[i] == false)
			return false;
	}
	return true;
}

int main()
{
	int t;
	string input;
	cin >> t;
	cin >> ws;
	for(int i = 0; i < t; i++)
	{
		getline(cin, input);
		bool result = checkPangram(input);
		if(result)
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
	}
	return 0;
}
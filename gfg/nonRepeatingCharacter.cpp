#include <bits/stdc++.h>

using namespace std;

int nonRepeatingCharacter(string input)
{
	map<char, bool> repeatingChar;
	for(int i = 0; i < input.length(); i++)
	{
		if(repeatingChar.find(input[i]) == repeatingChar.end())
			repeatingChar[input[i]] = false;
		else if(repeatingChar[input[i]] == false)
			repeatingChar[input[i]] = true;
	}
	for(int i = 0; i < input.length(); i++)
	{
		if(repeatingChar[input[i]] == false)
		{
			return (i);
		}
	}
	return (-1);
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
		int result = nonRepeatingCharacter(input);
		if(result == -1)
			cout << -1 << "\n";
		else
			cout << input[result] << "\n";
	}
	return 0;
}
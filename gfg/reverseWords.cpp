//http://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string/0
#include <bits/stdc++.h>

using namespace std;

void reverseWords(string input)
{
	vector<string> output;
	vector<char> tempOut;
	for(int i = 0; i < input.length(); i++)
	{
		if(input[i] == '.')
		{
			string temp(tempOut.begin(), tempOut.end());
			output.push_back(temp);
			tempOut.clear();
		}
		else
			tempOut.push_back(input[i]);
	}
	string temp(tempOut.begin(), tempOut.end());
	output.push_back(temp);
	tempOut.clear();
	for(int i = output.size() - 1; i > 0; i--)
		cout << output[i] << ".";
	cout << output[0] << "\n";
}

int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		string input;
		cin >> input;
		reverseWords(input);
	}
	return 0;
}
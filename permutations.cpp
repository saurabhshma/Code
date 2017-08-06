//http://practice.geeksforgeeks.org/problems/permutations-of-a-given-string/0
#include <bits/stdc++.h>

using namespace std;

int generatePermutations(string& input, int start, int n)
{
	if(start == n - 1)
	{
		cout << input << " ";
	}
	for(int i = start; i < n; i++)
	{
		sort(input.begin() + start, input.end());
		swap(input[start], input[i]);
		generatePermutations(input, start + 1, n);
		swap(input[start], input[i]);
	}
}

int main()
{
	int t;
	cin >> t;
	string input;
	for(int i = 0; i < t; i++)
	{
		cin >> input;
		sort(input.begin(), input.end());
		generatePermutations(input, 0, input.length());
		cout << "\n";
	}
	return 0;
}
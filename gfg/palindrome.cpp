//http://practice.geeksforgeeks.org/problems/palindrome/0
#include <bits/stdc++.h>

using namespace std;

bool palindrome(int n)
{
	vector<int> number;
	while(n != 0)
	{
		number.push_back(n % 10);
		n = n / 10;
	}
	// cout << n << " " << number.size() << "\n";
	for(int i = 0, j = number.size() - 1; i <= j; i++, j--)
	{
		if(number[i] != number[j])
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int t, n;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n;
		bool result = palindrome(n);
		if(result)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}
//http://practice.geeksforgeeks.org/problems/key-pair/0
//using hashmap
#include <bits/stdc++.h>

using namespace std;

bool keyPair(int A[], int key, int n)
{
	map<int, int> input;
	for(int i = 0; i < n; i++)
		input[A[i]] = A[i];
	for(int i = 0; i < n; i++)
	{
		if(A[i] > key)
			continue;
		else
		{
			if(input.find(key - A[i]) == input.end())
				continue;
			else
				return true;
		}
	}
	return false;
}

int main()
{
	int t, n, key;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n >> key;
		int A[n];
		for(int j = 0; j < n; j++)
			cin >> A[j];
		bool result = keyPair(A, key, n);
		if(result == false)
			cout << "No\n";
		else
			cout << "Yes\n";
	}	
	return 0;
}
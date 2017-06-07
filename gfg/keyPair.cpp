//http://practice.geeksforgeeks.org/problems/key-pair/0
#include <bits/stdc++.h>

using namespace std;

bool keyPair(int A[], int key, int n)
{
	sort(A, A + n);
	int i = 0, j = n - 1;
	while(i != j)
	{
		if((A[i] + A[j]) > key)
			j--;
		else if((A[i] + A[j]) < key)
			i++;
		else
			return true;
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
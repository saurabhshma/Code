//http://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0

#include <bits/stdc++.h>

using namespace std;

int c = 0;

int findNearest(int n, int aux[])
{
	for(int i = 0; i <= n; i++)
	{
		if(aux[i] >= n)
			return i; 
	}
}

int minJumps(int A[], int aux[], int n)
{
	if(n == 0)
		return 0;
	else
	{
		int index = findNearest(n, aux);
		c++;
		minJumps(A, aux, index);
	}

}

int main()
{
	int t, n;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n;
		int A[n], aux[n];
		for(int j = 0; j < n; j++)
			cin >> A[j];
		for(int j = 0; j < n; j++)
		{
			int temp = A[j] + j;
			if(temp < n)
				aux[j] = temp;
			else
				aux[j] = n - 1;
		}
		c = 0;
		if(A[0] == 0)
			cout << -1 << "\n";
		else
		{
			minJumps(A, aux, n - 1);
			cout << c << "\n";
		}
	}
	return 0;
}
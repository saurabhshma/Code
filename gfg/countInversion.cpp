//http://practice.geeksforgeeks.org/problems/inversion-of-array/0
#include <bits/stdc++.h>

using namespace std;

// int countInverse = 0;

int countAcross(int A[], int aux[], int start, int mid, int end)
{
	int i = start, j = mid + 1;
	int countInverse = 0;
	int index = start;
	// for(int k = 0; k < 3; k++)
	// 	cout << A[k] << " ";
	// cout << "\n";
	while(index <= end)
	{
		if(j > end)
		{
			for(int x = i; x <= mid; x++)
			{
				aux[index] = A[x];
				index++;
			}
		}
		else if(i > mid)
		{
			for(int x = j; x <= end; x++)
			{
				aux[index] = A[x];
				index++;
			}
		}
		else if(A[i] > A[j])
		{
			countInverse += mid - i + 1;
			aux[index] = A[j];
			j++;
			index++;
		}
		else
		{
			aux[index] = A[i];
			i++;
			index++;
		}
	}
	for(int x = start; x <= end; x++)
		A[x] = aux[x];
	return countInverse;
}


int countInversion(int A[], int aux[], int start, int end)
{
	if(start == end)
		return 0;
	else
	{
		int mid = (start + end) / 2;
		int left = countInversion(A, aux, start, mid);
		int right = countInversion(A, aux, mid + 1, end);
		int across = countAcross(A, aux, start, mid, end);
		return (left + right + across);
	}	
}

int main()
{
	int t, n;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		// countInverse = 0;
		cin >> n;
		int A[n], aux[n];
		for(int j = 0; j < n; j++)
		{
			cin >> A[j];
		}
		int result = countInversion(A, aux, 0, n - 1);
		cout << result << "\n";
	}
	return 0;
}
//http://practice.geeksforgeeks.org/problems/stock-buy-and-sell/0
#include <bits/stdc++.h>

using namespace std;

void stockBuyAndSell(int A[], int n)
{
	int start = 0, end = -1;
	for(int i = 1; i < n; i++)
	{
		if(A[i] < A[i - 1])
		{
			if(end != -1)
			{
			    cout << "(" << start << " " << end << ") ";
			    end = -1;
			}
			start = i;
		}
		else
		{
			end = i;
		}
	}
	if(end != -1)
	    cout << "(" << start << " " << end << ") ";
}

int main()
{
	int t, n;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n;
		int A[n];
		for(int j = 0; j < n; j++)
		{
			cin >> A[j];
		}
		int flag = 0;
		for(int j = 1; j < n; j++)
		{
		    if(A[j] >= A[j - 1])
		    { 
		        flag = 1;
		        break;
		    }
		}
		if(flag == 1)
		    stockBuyAndSell(A, n);
		else
		    cout << "No Profit";
		cout << "\n";
	}
	return 0;
}
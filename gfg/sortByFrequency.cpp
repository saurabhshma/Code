//http://practice.geeksforgeeks.org/problems/sorting-elements-of-an-array-by-frequency/0

#include <bits/stdc++.h>

using namespace std;

struct node
{
	int number;
	int count;
};

// void sortByFreq(int A[], int n)
// {

// }

bool comparator(node A, node B)
{
    if(A.count > B.count)
        return true;
    else if(A.count == B.count)
        return (A.number < B.number);
	else
	    return false;
}

int main()
{
	int t, n, temp;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n;
		map<int, int> A;
		for(int j = 0; j < n; j++)
		{
			cin >> temp;
			if(A.find(temp) == A.end())
				A[temp] = 1;
			else
				A[temp]++;
		}
		map<int, int>::iterator it;
		node arr[A.size()];
		int j = 0;
		for(it = A.begin(); it != A.end(); it++, j++)
		{
			arr[j].number = it->first;
			arr[j].count = it->second;
		}
		// for(int j = 0; j < A.size(); j++)
		// 	cout << "Number: " << arr[j].number << " count: " << arr[j].count << "\n";
		sort(arr, arr + A.size(), comparator);
		// // cout << "\n";
		// for(int j = 0; j < A.size(); j++)
		// 	cout << "Number: " << arr[j].number << " count: " << arr[j].count << "\n";
		for(int j = 0; j < A.size(); j++)
		{
			int tempCount = arr[j].count;
			for(int k = 0; k < tempCount; k++)
				cout << arr[j].number << " ";
		}
		cout << "\n";
	}
	return 0;
}
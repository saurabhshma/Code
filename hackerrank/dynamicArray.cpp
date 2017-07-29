//https://www.hackerrank.com/challenges/dynamic-array
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, q;
	int val, x, y, lastAnswer = 0;
	cin >> n >> q;
	vector< vector<int> > seqList(n, vector<int>(0));
	for(int i = 0; i < q; i++)
	{
		cin >> val >> x >> y;
		int temp = (x ^ lastAnswer) % n;
		if(val == 1)
			seqList[temp].push_back(y);
		else
		{
			lastAnswer = seqList[temp][(y % seqList[temp].size())];
			cout << lastAnswer << "\n";
		}
	}
	return 0;
}
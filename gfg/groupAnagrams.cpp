#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, n;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n;
		string input[n];
		for(int j = 0; j < n; j++)
		{
			cin >> input[j];
		}
		for(int j = 0; j < n; j++)
		{
			sort(input[j].begin(), input[j].end());
		}
		map<string, int> count;
		for(int j = 0; j < n; j++)
		{
			if(count.find(input[j]) == count.end())
				count[input[j]] = 1;
			else
				count[input[j]]++;
		}
		vector<int> result;
		for(map<string, int>::iterator it = count.begin(); it != count.end(); it++)
		{
			result.push_back(it->second);
		}
		sort(result.begin(), result.end());
		for(int j = 0; j < result.size(); j++)
			cout << result[j] << " ";
		cout << "\n";
	}
	return 0;
}
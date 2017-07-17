//http://practice.geeksforgeeks.org/problems/number-of-days/0
#include <bits/stdc++.h>

using namespace std;

int main()
{
	double r, s, q; 
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> r >> s >> q;
		if(r > q)
			cout << 1 << "\n";
		else if((floor(q / (r - s)) * (r - s) + s) > q)
			cout << floor(q / (r - s)) << "\n";
		else
			cout << ceil(q / (r - s)) << "\n";
	}
	return 0;
}
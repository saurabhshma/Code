//http://practice.geeksforgeeks.org/problems/minimum-platforms/0
#include <bits/stdc++.h>

using namespace std;

int minPlatforms(int Arrival[], int Departure[], int n)
{
	int max = 1;
	int platforms = 1;
	int a = 1, d = 0;
	while(a < n)
	{
		if(Arrival[a] >= Departure[d])
		{
			d++;
			platforms--;
		}
		else
		{
			a++;
			platforms++;
			if(platforms > max)
				max = platforms;
		}
	}
	return max;
}

int main()
{
	int t, n;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n;
		int Arrival[n], Departure[n];
		for(int j = 0; j < n; j++)
			cin >> Arrival[j];
		for(int j = 0; j < n; j++)
			cin >> Departure[j];
		sort(Arrival, Arrival + n);
		sort(Departure, Departure + n);
		int result = minPlatforms(Arrival, Departure, n);
		cout << result << "\n";
	}
	return 0;
}
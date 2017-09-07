#include <bits/stdc++.h>

using namespace std;

bool isPower(long long int n)
{
	if(n == 0)
	    return 0;
	else
	{
	    while(n > 1)
	    {
	        if(n % 2 == 1)
	            return false;
	        n = n / 2;
	    }
	    return true;
	}
	// return n && (!(n&(n-1)));
}

int main()
{
	int t;
	bool result;
	cin >> t;
	long long int n;
	// cout << "size : " << sizeof(unsigned long long int) << "\n";
	for(int i = 0; i < t; i++)
	{
		cin >> n;
		if(n % 2 == 0)
		{
			bool result = isPower(n);
			if(result == true)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		else
		{
			if(n == 1)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
	return 0;
}
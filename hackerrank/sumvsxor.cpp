#include <iostream>

using namespace std;

int main()
{
	int n, x = 1;
	unsigned int temp = 1;
	cin >> n;
	temp <<=31;
	if(n == 0)
		x = 1;
	else
	{
		while((temp & n) == 0)
			temp >>= 1;
		while(temp != 0)
		{
			if((temp & n) == 0)
				x = x * 2;
			temp >>= 1;
		}
	}
	cout << x << "\n";
	return 0;
}
//http://practice.geeksforgeeks.org/problems/ugly-numbers/0
#include <bits/stdc++.h>

using namespace std;

int uglyN[501];

int returnMultiple(int number, int n)
{
	return (uglyN[n] * number);
}

int nthUgly(int n)
{
	if(n == 1)
		return 1;
	else
	{
		uglyN[1] = 1;
		int twosMultiple, threesMultiple, fivesMultiple, temp2, temp3, temp5, result;
		twosMultiple = 1;
		threesMultiple = 1;
		fivesMultiple = 1;
		for(int i = 2; i <= n; i++)
		{
			temp2 = returnMultiple(2, twosMultiple);
			temp3 = returnMultiple(3, threesMultiple);
			temp5 = returnMultiple(5, fivesMultiple);
			if(temp2 < temp3)
			{
				if(temp5 < temp2)
				{
					result = temp5;
					fivesMultiple++;
				}
				else
				{
					result = temp2;
					if(temp2 == temp5)
					{
						twosMultiple++;
						fivesMultiple++;
					}
					else
						twosMultiple++;
				}
				
			}
			else
			{
				if(temp5 < temp3)
				{
					result = temp5;
					fivesMultiple++;
				}
				else
				{
					result = temp3;
					if(temp2 == temp3)
					{
						if(temp2 == temp5)
						{	
							twosMultiple++;
							threesMultiple++;
							fivesMultiple++;
						}
						else
						{
							twosMultiple++;
							threesMultiple++;	
						}

					}
					else if(temp3 == temp5)
					{
						if(temp2 == temp5)
						{	
							twosMultiple++;
							threesMultiple++;
							fivesMultiple++;
						}
						else
						{
							fivesMultiple++;
							threesMultiple++;	
						}
					}
					else
						threesMultiple++;
				}
			}
			uglyN[i] = result;
		}
		return uglyN[n];
	}
}

int main()
{
	int t, n;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n;
		int result = nthUgly(n);
		cout << result << "\n";
	}
	return 0;
}
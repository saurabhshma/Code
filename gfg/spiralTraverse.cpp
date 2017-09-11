//http://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix/0
#include <bits/stdc++.h>

using namespace std;

void spiralTraverse(vector< vector<int> >& input)
{
	int rdluFlag = 0;
	int u = 0, r = 3, d = 3, l = 0;
	int count = 0;
	int row = 0, column = 0;
	while(1)
	{
		if(count == 16)
			break;
		else
		{
			// cout << "\nrdluflag: " << rdluFlag << "\n";
			// cout << "Count: " << count << "\n";
			if(rdluFlag == 0)
			{
				while(column <= r)
				{
					cout << input[row][column] << " ";
					count++;
					column++;
				}
				column--;
				row++;
				u++;
				rdluFlag = (rdluFlag + 1) % 4;
			}
			else if(rdluFlag == 1)
			{
				while(row <= d)
				{
					cout << input[row][column] << " ";
					count++;
					row++;
				}
				row--;
				column--;
				r--;
				rdluFlag = (rdluFlag + 1) % 4;
			}
			else if(rdluFlag == 2)
			{
				while(column >= l)
				{
					cout << input[row][column] << " ";
					count++;
					column--;
				}
				column++;
				row--;
				d--;
				rdluFlag = (rdluFlag + 1) % 4;
			}
			else
			{
				while(row >= u)
				{
					cout << input[row][column] << " ";
					count++;
					row--;
				}
				row++;
				column++;
				l++;
				rdluFlag = (rdluFlag + 1) % 4;
			}
		}
	}
	cout << "\n";
}

int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		vector<vector<int> > input(4, vector<int>(4));
		for(int j = 0; j < 4; j++)
		{
			for(int k = 0; k < 4; k++)
			{
				cin >> input[j][k];
			}
		}
		// for(int j = 0; j < 4; j++)
		// {
		// 	for(int k = 0; k < 4; k++)
		// 	{
		// 		cout << input[j][k] << " ";
		// 	}
		// 	cout << "\n";
		// }
		spiralTraverse(input);
	}
	return 0;
}
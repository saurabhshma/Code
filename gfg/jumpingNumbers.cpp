//http://practice.geeksforgeeks.org/problems/jumping-numbers/0

#include <bits/stdc++.h>

using namespace std;

void printJumpingNumbers(int start, int n)
{
	queue<int> jumpingQueue;
	jumpingQueue.push(start);
	int temp, temp1;
	while(!jumpingQueue.empty())
	{
		// cout << "hello\n";
		// cout << "lolo " << jumpingQueue.front() << "\n";
		temp = jumpingQueue.front();
		// cout << "temp " << temp << "\n";
		temp1 = temp * 10 + temp % 10;
		if(temp1 % 10 == 0)
		{
			if(temp1 + 1 <= n)
				jumpingQueue.push(temp1 + 1);
		}
		else if(temp1 % 10 == 9)
		{
			if(temp1 - 1 <= n)
				jumpingQueue.push(temp1 - 1);
		}
		else
		{
			if(temp1 - 1  <= n)
				jumpingQueue.push(temp1 - 1);
			if(temp1 + 1 <= n)
				jumpingQueue.push(temp1 + 1);
		}
		
		cout << temp << " ";
		jumpingQueue.pop();
	}
}

int main()
{
	int t, n, start, digits;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n;
		start = 0;
		cout << start << " ";
		for(int j = start + 1; j < 10; j++)
			printJumpingNumbers(j, n);
		cout << "\n";
	}
	return 0;
}
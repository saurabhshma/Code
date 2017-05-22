//https://www.hackerrank.com/challenges/circular-array-rotation

#include <iostream>

using namespace std;

int main()
{
	int n, k, q, m;
	cin >> n >> k >> q;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	for(int i = 0; i < q; i++)
	{
		cin >> m;
		cout << arr[(n - (k % n) + m) % n] << "\n";
	}
	return 0;
}
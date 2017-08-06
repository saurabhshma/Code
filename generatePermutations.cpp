#include <bits/stdc++.h>

using namespace std;

void display(int input[], int n)
{
	for(int i = 0; i < n; i++)
		cout << input[i] << " ";
	cout << "\n";
}

int generatePermutations(int input[], int start, int n)
{
	if(start == n - 1)
	{
		display(input, n);
	}
	for(int i = start; i < n; i++)
	{
		swap(input[start], input[i]);
		generatePermutations(input, start + 1, n);
		swap(input[start], input[i]);
	}
}

int main()
{
	int n;
	cout << "Enter value of n\n";
	cin >> n;
	int input[n];
	cout << "Enter the values\n";
	for(int i = 0; i < n; i++)
		cin >> input[i];
	cout << "All the permutations\n";
	generatePermutations(input, 0, n);
	return 0;
}
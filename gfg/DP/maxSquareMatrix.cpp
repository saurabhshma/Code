//http://www.geeksforgeeks.org/maximum-size-sub-matrix-with-all-1s-in-a-binary-matrix/

#include <bits/stdc++.h>

using namespace std;

int maxSquareMatrix(int A[6][5], int row, int col)
{
	int auxMat[row][col], temp;
	for(int i = 0; i < row; i++)
		auxMat[i][0] = A[i][0];
	for(int i = 0; i < col; i++)
		auxMat[0][i] = A[0][i];
	for(int i = 1; i < row; i++)
	{
		for(int j = 1; j < col; j++)
		{
			if(A[i][j] == 1)
				auxMat[i][j] = min(min(auxMat[i - 1][j], auxMat[i][j - 1]), auxMat[i - 1][j - 1]) + 1;
			else
				auxMat[i][j] = 0;
		}
	}
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			cout << auxMat[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}

int main()
{
	int row, col, t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> row >> col;
		int A[row][5];
		for(int j = 0; j < row; j++)
			for(int k = 0; k < col; k++)
				cin >> A[j][k];
		int result = maxSquareMatrix(A, row, col);
		cout << result << "\n";
	}

	return 0;
}
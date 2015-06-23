#include <stdio.h>
#include <limits.h>

int mcm(int a, int b);
void printsol(int i, int j);
int P[7] = {30, 35, 15, 5, 10, 20, 25};
int A[6][6], S[6][6];

int main()
{
	int i, j;
	for(i = 0; i < 6; i++)
	{	
		for(j = 0; j < 6; j++)
		{
			A[i][j] = -1;
		}
	}
	for(i = 0; i < 6; i++)
	{	
		for(j = 0; j < 6; j++)
		{
			S[i][j] = 0;
		}
	}
	int result = mcm(1, 6);
	for(i = 0; i < 6; i++)
	{	
		for(j = 0; j < 6; j++)
		{
			printf("%d ", A[i][j]); 
		}
		printf("\n");
	}

	printf("\n");

	for(i = 0; i < 6; i++)
	{	
		for(j = 0; j < 6; j++)
		{
			printf("%d ", S[i][j]); 
		}
		printf("\n");
	}
	printf("\n");
	printf("Result: %d\n", result);
	printf("Solution: ");
	printsol(1, 6);
	printf("\n");
	return 0;
}

int mcm(int a, int b)
{
	int k, min = INT_MAX, temp;
	if(b == a)
		return 0;
	else
	{
		for(k = a; k < b; k++)
		{
			if(A[a - 1][k - 1] == -1)
				A[a - 1][k - 1] = mcm(a, k);

			if(A[k][b - 1] == -1)
				A[k][b - 1] = mcm(k + 1, b);
	
			temp =  A[a - 1][k - 1] + A[k][b - 1] + P[a - 1] * P[b] * P[k];
			if(temp < min)
			{
				min = temp;
				A[a - 1][b - 1] = min;
				S[a - 1][b - 1]	= k;
			}
		}
		return min;
	}
}

void printsol(int i, int j)
{
	if(i == j)
		printf("A%d", i);
	else
	{
		printf("(");
		printsol(i, S[i - 1][j - 1]);
		printsol(S[i - 1][j - 1] + 1, j);
		printf(")");
	}
}

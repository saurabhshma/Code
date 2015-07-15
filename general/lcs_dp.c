#include <stdio.h>
#include <string.h>
#include <limits.h>

char X[] = "abc";
char Y[] = "bcd";
int A[4][4];

int lcs(int a, int b);

int main()
{
	int i, j;
	printf("%d %d\n", strlen(X), strlen(Y));
	for(i = 0; i <= strlen(X); i++)
		for(j = 0; j <= strlen(Y); j++)
			A[i][j] = -1;
	
	/*for(i = 0; i <= strlen(X); i++)
		A[i][0] = 0;
	
	for(i = 0; i <= strlen(Y); i++)
		A[0][i] = 0;
	*/
	int result = lcs(strlen(X), strlen(Y));
	printf("Result : %d\n", result);
	
	for(i = 0; i <= strlen(X); i++)
	{
		for(j = 0; j <= strlen(Y); j++)
		{
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	return 0;
}

int lcs(int a, int b)
{
//	int sol1, sol2, sol3;
	if( a == 0 || b == 0)
		return 0;

      if ( A[a][b] >= 0 )
      {
         return( A[a][b] );
      }

 /*     if ( X[a-1] == Y[b-1] )
      {
         sol1 = lcs(a-1, b-1);

         A[a][b] = sol1 + 1;
         return( A[a][b] );
      }
      else
      {
         sol2 = lcs(a-1, b);
         sol3 = lcs(a, b-1);

         A[a][b] = (sol2 >= sol3) ? sol2 : sol3;

         return( A[a][b] );
      }
}*/
	else
	{
		if(X[a - 1] == Y[b - 1])
		{	
			if(A[a - 1][b - 1] == -1) 
			{
				A[a - 1][b - 1] = lcs(a - 1, b - 1);
				A[a][b] = 1 + A[a - 1][b - 1];
				return A[a][b];
			}
		}
		else
		{
			if(A[a - 1][b] == -1)
				A[a - 1][b] = lcs(a - 1, b);
			if(A[a][b - 1] == -1)
				A[a][b - 1] = lcs(a, b - 1);
			if(A[a - 1][b] > A[a][b - 1])
				A[a][b] = A[a - 1][b];
			else
				A[a][b] = A[a][b - 1];		
		}
		return(A[a][b]);
	}
}

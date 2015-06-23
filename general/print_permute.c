#include <stdio.h>

char A[4] = "abcd";
void permute(int a, int b);
void swap(char *a, char *b);

int main()
{
	permute(1, 4);		
	return 0;
}

void permute(int a, int b)
{
	int i;
	if(a == b)
		printf("%s\n", A);
	else
	{
		for(i = a - 1; i < b; i++)
		{
			swap(&A[a - 1], &A[i]);
			permute(a + 1, b);
			swap(&A[a - 1], &A[i]);
		} 
	}
}

void swap(char *a, char *b)
{
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;	
}

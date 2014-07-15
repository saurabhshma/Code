#include<stdio.h>

int main()

{
	int i = 32, n, r, q;
	char B[32];
	printf("Enter the Number\n");
	scanf("%d", &n);
	q = n;
	while(q >= 1)
	{
	r = q % 2;
	B[i - 1] = r;
	q = q / 2;
	i--;
	}
	
	
	for(i; i < 32; i++)
	printf("%d", B[i]);
	printf("\n");
	return 0;
}

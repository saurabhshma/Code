#include <stdio.h>
int fact(int a)
{  
	int i, x = 1;
	for(i = a; i >= 1; i--)
	{
	x = x * i;
	}
	return x;
}

int main()
{
	int a, b;
	printf("Enter A and B \n");
	scanf("%d %d", &a, &b);
	int i, temp = 1, temp2;
	for(i = b; i >=1; i--)
	{
	if(a != 0)
	{
	temp = temp * a;
	a--;
	}
	temp2 = temp / (fact(b));
	} 
	printf("%d\n", temp2);
	return 0; 
}

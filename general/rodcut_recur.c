#include <stdio.h>
#define SIZE 20

int rodcut_recur(int l);
int P[SIZE] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

int main()
{
	int price, i;
	for(i = 1; i <= SIZE; i++) 
	{	
		price = rodcut_recur(i);
		printf("Maximum price for length %d = %d\n", i, price);
	}
	return 0;
}

int rodcut_recur(int l)
{
	int max = P[l - 1], i, temp;
	if(l == 1)
		return P[0];
	else
	{
		for(i = 1; i <= l/2; i++)
		{
			temp = rodcut_recur(i) + rodcut_recur(l - i);
			if(max < temp)
				max = temp;
		}
		return max;
	}
}

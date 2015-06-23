#include <stdio.h>
#define SIZE 20

int rodcut_dp(int l);
int printsol(int l);
int P[SIZE] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
int MP[SIZE] = {1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
int S[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

int main()
{
	int price, i;
	for(i = 1; i <= SIZE; i++) 
	{	
		price = rodcut_dp(i);
		printf("Maximum price for length %d = %d\n", i, price);
		printsol(i);
		printf("\n");
	}
	return 0;
}

int rodcut_dp(int l)
{
	int max = P[l - 1], i, temp;
	if(l == 1)
	{
		printf("%d ", l);
		return P[0];
	}
	else
	{
		for(i = 1; i <= l/2; i++)
		{
			if(MP[i - 1] == -1)
				MP[i - 1] = rodcut_dp(i);
			if(MP[l - i - 1] == -1)
				MP[l - i - 1] = rodcut_dp(l - i);
			temp = MP[i - 1] + MP[l - i - 1];
			if(max < temp)
			{			
				max = temp;
				S[l - 1] = S[i - 1];
			}
		}
		return max;
	}
}

int printsol(int l)
{
	while(l > 0)
	{
		printf("%d ", S[l - 1]);
		l = l - S[l - 1];
	}	
}

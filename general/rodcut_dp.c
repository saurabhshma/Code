#include <stdio.h>
#define SIZE 20

int rodcut_dp(int l);
int P[SIZE] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
int MP[SIZE] = {1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

int main()
{
	int price, i;
	for(i = 1; i <= SIZE; i++) 
	{	
		price = rodcut_dp(i);
		printf("Maximum price for length %d = %d\n", i, price);
	}
	return 0;
}

int rodcut_dp(int l)
{
	int max = P[l - 1], i, temp;
	if(l == 1)
		return P[0];
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
				max = temp;
		}
		return max;
	}
}

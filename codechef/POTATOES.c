#include <stdio.h>
#include <math.h>

int flag;
void checkprime(int);
int main()
{
	int t, i, x, y, temp;
	scanf("%d", &t);
	for(i = 0; i < t; i++)
	{	
		scanf("%d %d", &x, &y);
		temp = x + y + 1;
		do
		{
			flag = 0;
			checkprime(temp);
			if(flag == 1)
			{
				temp++;
			}
		}while(flag == 1);
		printf("%d\n", temp - x - y );
	}
	return 0;
}

void checkprime(int temp)
{
	int n = sqrt(temp);
	int i;
	for(i = 2; i <= n; i++)
	{
		if(temp % i == 0)
		{
			flag = 1;
			break;
		}
	}
}

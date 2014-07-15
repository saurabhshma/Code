#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	char ip[16], temp[4], ch;
	int temp_num[4], i = 0, j = 0, k = 0, counter = 0;
	unsigned long ip_hex = 0;
	scanf("%s", ip);
	do
	{
		if(isdigit(ip[i]))
		{
			temp[j] = ip[i];
			i++, j++;
		}

		else if(ip[i] == '.')
		{
			counter++;
			if(counter > 3)
			{
				printf("Wrong IP!\n");
				exit(1);
			}
			else
			{
				temp[j] = '\0';
				temp_num[k] = atoi(temp);
				if(temp_num[k] > 255)
				{
					printf("Wrong IP\n");
					exit(1);	
				}
				else
				{
					k++;
					j = 0;
					i++;
				}
			}
		}	
		
		else
		{
			printf("Wrong IP\n");
			exit(1);
		}	
	}while(ip[i] != '\0');

	temp[j] = '\0';
	temp_num[k] = atoi(temp);
	if(temp_num[k] > 255)
	{
		printf("Wrong IP\n");
		exit(1);	
	}
	int x = 24;
	for(k = 0; k < 4; k++)
	{
		ip_hex = ip_hex + (temp_num[k] << x);
		x = x - 8;
	}
	printf("Result = %lu\n", ip_hex);
	return 0;
}

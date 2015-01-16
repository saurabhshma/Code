#include <stdio.h>

int main()
{
	int c, flag = 0;
	while((c = getchar()) != EOF)
	{
		if(flag == 0)
		{
			if(c == ' ')
			{	
				putchar(c);
				flag = 1;
			}
			else
				putchar(c);
		}
		else if(flag == 1 && c != ' ')
		{
			putchar(c);
			flag = 0;
		}
	}
	return 0;
}

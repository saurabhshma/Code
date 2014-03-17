#include <stdio.h>
#include <ctype.h>

int main()
{
	char c, temp;
	scanf("\n%c", &c);
	/*if(c == '^')
	{
		printf("1\n");
	}
	
	else if(c == '/' || c == '*')
	{
		if((temp == '+') || (temp == '-'))
		{
			printf("1\n");
		}
		
		else
		{
			printf("0\n");
		}
	}

	else
	{
		printf("0\n");
	}*/
	if(isalpha(c))
	{
		printf("ALPHA\n");
	}
	
	else
	{
		printf("NOTALPHA\n");
	}
	return 0;
	
}	

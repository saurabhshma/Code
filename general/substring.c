#include<stdio.h>
#include<string.h>

int main()
{
	int i = 0, j, k, m, n, flag, pos;
	char A[50], B[20];
	printf("Enter main String \n");
	gets(A);
	printf("Enter Substring \n");
	gets(B);
	m = strlen(A);
	n = strlen(B);
	while (i < m)
	{
		j = 0;
		if (A[i] == B[j])
		{
			
			for (j = 1; j < n; j++)
			{
				if (A[i + j] == B[j])
				{
					pos = i + j + 1;
					flag = 1;
				}	
				
				else
				{	
					flag = 0;
					i = i + j;
					break;
				}	
			}
		
			if (flag == 1)
			{
				printf("String Found!\n");
				break;
			}
		}
		
		else
			i++;

	}
	
	if (flag == 0)
	{
		printf("String Not Found!\n");
		return 0;
	}	
	
	//Deleting the string

	do
	{
		A[pos - n] = A[pos];
		pos++;
	
	} while (A[pos - n] != '\0');

	
	
	printf("Deleted String is \n");
	puts(A);

	return 0;
}

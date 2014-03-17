#include <stdio.h>

int a();

void main()
{
	if(a() == 1)
	printf("%d\n", a());
}

int a()
{
	return 1;
}
	

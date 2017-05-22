#include <stdio.h>

#define A(x) #x = 10
#define DINO_VERSION(type,var) type DINO_VERSION_#var = var

int main()
{
	DINO_VERSION(int, 1);
	printf("%d\n", DINO_VERSION_1);
	return 0;
}
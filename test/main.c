#include <stdlib.h>
#include <stdio.h>
#include "reciprocal.hpp"

int main (int argc, char **argv)
{
int i;
i = atoi (argv[1]);
printf ("The reciprocal of %d is %f\n", i, reciprocal (i));
return 0;
}


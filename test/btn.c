#include <stdio.h>

int main()
{
	int b, t, n;
	b = t = n = 0;
	char c;
	while((c = getchar()) != EOF)
	{
		if(c == '\n')
			n++;
		else if(c == ' ')
			b++;
		else if(c == '\t')
			t++;
		else
			continue;
	}
	printf("Number of blanks: %d\nNumber of tabs: %d\nNumber of newlines: %d\n", b, t, n);
	return 0;
}

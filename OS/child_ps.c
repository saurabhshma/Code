#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	if(pid < 0)
	{
		fprintf(stderr, "Fork Failed\n");
		return 1;
	}
	
	else
	{
		execlp("/bin/ls", "ls", NULL);
	}

/*	else
	{
		wait(NULL);
		printf("Child Complete\n");
	}
*/	
	return 0;
}

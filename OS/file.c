#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


int main()
{
	int fd;
	char a;
	ssize_t n;
	fd = open("./child_ps", O_RDWR);
	if(fd == -1)
	{
		printf("Error\n");
	}
	n = read(fd, &a, sizeof(char));
	printf("a = %c\nn = %d\n", a, n);
	return 0;
}

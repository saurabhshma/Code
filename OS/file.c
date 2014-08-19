#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argv, char *argc[])
{
	int fd;
	mode_t mode = S_IRUSR | S_IWUSR;
	fd = open(argc[1], O_RDWR | O_CREAT, mode);
	char *data = argc[2];
	if(fd == -1)
	{
		perror("open");
	}
	ssize_t length = strlen(data);
	write(fd, argc[2], length);
	return 0;
}

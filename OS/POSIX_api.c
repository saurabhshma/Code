#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>

int main()
{
	int seg_id;
	char *shared_mem;
	seg_id = shmget(IPC_PRIVATE, 4096, S_IRUSR | S_IWUSR);
	shared_mem = (char*)shmat(seg_id, NULL, 0);
	sprintf(shared_mem, "Yo biatch");
	printf("%s\n", shared_mem);
	shmdt(shared_mem);
	shmctl(seg_id, IPC_RMID, NULL);
	return 0;
}

#include <stdio.h>
#include <sys/stat.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>

void main()
{
	pid_t pid;
	char *sm;
	int seg, i = 0;
	char a = 'a';
	seg = shmget(IPC_PRIVATE, 4096, S_IRUSR | S_IWUSR);
	sm = (char*)shmat(seg, NULL, 0);
	strcpy(sm, "hello");
	//sprintf(sm, "hello");
	pid = fork();
	if(pid == 0)
	{	
		sm = (char*)shmat(seg, NULL, 0);
		while(i < 20)
		{	
			printf("child %s\n", sm);
			sm[1] = a;
			a++;
			i++;
		}
		shmdt(sm);
	//	shmctl(seg, IPC_RMID, NULL);
	}
			
	else
	{
		//sm = (char*)shmat(seg, NULL, 0);
		//strcpy(sm, "hello");
		//sprintf(sm, "hello");
		while(i < 20)
		{
			printf("\tparent %s\n", sm);
			sm[0] = a;
			a++;
			i++;
		}
		shmdt(sm);
		//shmctl(seg, IPC_RMID, NULL);
	}
	//return 0;
}

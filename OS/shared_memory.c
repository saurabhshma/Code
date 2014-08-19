#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/stat.h>

#define BUF_SIZE 5

void producer();
void consumer();
void display();

int in, out, x;
int main()
{
	int i = 0, seg_id, *A, j;
	pid_t pid;
	seg_id = shmget(IPC_PRIVATE, (BUF_SIZE + 3) * sizeof(int), S_IRUSR | S_IWUSR);
	A = (int*)shmat(seg_id, NULL, 0);
	A[BUF_SIZE] = 0; //in
	A[BUF_SIZE + 1] = 0; //out
	A[BUF_SIZE + 2] = 1; //x
	pid = fork();
	if(pid == 0)
	{
		A = (int*)shmat(seg_id, NULL, 0);		
		while(i < 10)
		{	
			printf("consumer\n");
			while(A[BUF_SIZE] == A[BUF_SIZE + 1])
			{
				printf("EMPTY BUFFER\n");
			}
			//x = A[A[BUF_SIZE + 1]];
			A[A[BUF_SIZE + 1]] = 0;
			A[BUF_SIZE + 1]  = (A[BUF_SIZE + 1]+ 1) % BUF_SIZE;
			for(j = 0; j < BUF_SIZE; j++)
				printf("%d ", A[j]);
			printf("\n");
			i++;
			//consumer();
		}
	}
	else
	{
	//	A = (int*)shmat(seg_id, NULL, 0);
		while(i < 10)
		{	
			printf("producer\n");
			while((A[BUF_SIZE] + 1) % BUF_SIZE == A[BUF_SIZE + 1])
			{
				printf("BUFFER FULL\n");
			}
			A[A[BUF_SIZE]] = A[BUF_SIZE + 2];
			A[BUF_SIZE + 2]++;
			A[BUF_SIZE] = (A[BUF_SIZE] + 1) % BUF_SIZE;
			for(j = 0; j < BUF_SIZE; j++)
				printf("%d ", A[j]);
			printf("\n");
			i++;
			//producer();
		}
	}
	return 0;
}

/*void producer()
{
	while((in + 1) % BUF_SIZE == out); 	
	A[in] = x;
	x++;
	in = (in + 1) % BUF_SIZE;
	display();
}

void consumer()
{
	while(in == out);
	x = A[out];
	out = (out + 1) % BUF_SIZE;
	display();
}

void display()
{
	int i;
	for(i = 0; i < BUF_SIZE; i++)
		printf("%d ", A[i]);
	printf("\n");
}*/	

/* ----------------------------------------------------------------- */
/* PROGRAM fork-02.c                                                 */
/*   This program runs two processes, a parent and a child.  Both of */
/* them run the same loop printing some messages.  Note that printf()*/
/* is used in this program.                                          */
/* ----------------------------------------------------------------- */

#include  <stdio.h>
#include  <sys/types.h>

#define   MAX_COUNT  200

void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(pid_t);               /* parent process prototype */

void  main(void)
{
     pid_t  pid;
     //printf("Hello\n");
     pid = fork();
     printf("Hello\n");
     if (pid == 0) 
          ChildProcess();
     else 
          ParentProcess(pid);
}

void  ChildProcess(void)
{
     int   i;

     for (i = 1; i <= MAX_COUNT; i++)
          printf("   This line is from child, value = %d\n", i);
     printf("   *** Child process is done ***\n");
}

void  ParentProcess(pid_t pid)
{
     int   i;

     for (i = 1; i <= MAX_COUNT; i++)
          printf("PID = %d, This line is from parent, value = %d\n", pid, i);
     printf("*** Parent is done ***\n");
}


#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	pid_t pid;
	int rv;
	pid = fork();	// Forks the address space of the program
	
	if(pid)
	{
		printf("This is the parent process \n");
		wait(&rv);
		printf("This is after the child process has exited, and has come to the parent process \n");
	}
	else
	{
		printf("This is inside the child process \n");
		printf("Now, planning to exit\n");
		scanf("%d",&rv);
		exit(rv);
		printf("This is probably not going to execute\n");
	}
	return 0;
}

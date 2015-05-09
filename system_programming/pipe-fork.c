#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int pfds[2];
	char buf[40];
	if(pipe(pfds)==-1)
	{
		perror("pipe");
		exit(1);
	}
	
	pid_t pid;
	pid = fork();
	if(pid)
	{
		wait(NULL);
		printf("In parent\n");
		printf("File descriptor for writing #%d\n", pfds[1]);
		printf("File descriptor for reading #%d\n", pfds[0]);
		read(pfds[0], buf, 11);
		printf("%s\n", buf);
		printf("In parent after child\n");
	}
	else
	{
		printf("In child\n");
		write(pfds[1], "from_child", 11);
		printf("Going out now\n");
		exit(0);
	}
	printf("Exiting \n");
	return 0;
}			

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <errno.h>
#include <unistd.h>
#include <sys/sem.h>

int sem_init(char *string, int b, int sem_num)
{
	int key = ftok(string, b);
	return semget(key, sem_num, 0666|IPC_CREAT);	
}

int main()
{
	int id = sem_init("pipe-fork.c", 'B', 10);
	printf("Semaphore ID = %d\n", id);
	return 0;	
}	

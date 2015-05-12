#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdlib.h>

struct message {
	long mtype;
	char text[20];
	};

int msgq_init(char *str, int b)
{       
        key_t key;
        int msqid;
        key = ftok(str, b);
        msqid = msgget(key, 0666|IPC_CREAT);
        printf("Message Id:%d\n", msqid);
	return msqid;   
} 

int main()
{
	pid_t pid;
	int msg_id = msgq_init("message121324.c", 'B');
	struct message m2;
	pid = fork();
	//struct message m1 = {2, "message_from_child"};	
	if(pid) 					// Parent Process
	{
		wait(NULL);
		msgrcv(msg_id, &m2, (sizeof(struct message) - sizeof(long)), 2, 0);
		printf("%s\n", m2.text);
	}	
	else
	{
		struct message m1 = {2, "message_from_child"};						//Child Process
		msgsnd(msg_id, &m1, (sizeof(struct message) - sizeof(long)), 0);
		exit(0);	
	}	
	return 0;
}

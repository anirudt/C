#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/msg.h>

struct message {
	long msg_type;
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
	int id = msgq_init("pipe-fork.c", 'b');	
	struct message m1 = {2, "First message"};
	struct message m2;
	msgsnd(id, &m1, (sizeof(struct message) - sizeof(long)), 0); 			// Sends a message to a queue of an ID
	msgrcv(id, &m2, (sizeof(struct message) - sizeof(long)), 2, 0);        		// Receives a message to a queue of an ID
	printf("%s\n", m2.text);
	return 0;
} 

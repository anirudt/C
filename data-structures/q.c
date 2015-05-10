#include <stdio.h>
#include <malloc.h>
#define MAXSIZE 10


typedef struct 
{
	int arr[MAXSIZE];
	int head, rear;
	/* data */
}queue;

void q_init(queue *q)
{
	q->head = 0;
	q->rear = 0;
}

void q_add(queue *q)
{
	//change these code lines appropriately 
	int n;
	printf("Enter the element you want to add\n");
	scanf("%d",&n);
	q->arr[q->head] = n;	
	q->head++;
}

void q_delete(queue *q)
{
	printf("Deleted element is %d\n", q->arr[0]);
	q->rear++;
}

int isEmpty(queue *q)
{
	if(q->head==0 && q->rear==0)
		return 1;
	else
		return 0;
}

int isFull(queue *q)
{
	if(q->head-q->rear==MAXSIZE)
		return 1;
	else
		return 0;
}

int main()
{
	int n,i,choice,j;
	j = 0;
	i = 0;
	queue *q;
	q = (queue *)malloc(sizeof(queue));
	while(i==0)
	{
		printf("Menu Driven Implementation of a Queue\n");
		printf("1. Initializing a queue\n");
		printf("2. Adding an element\n");
		printf("3. Deleting an element\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: q_init(q);
					break;
			case 2: q_add(q);
					break;
			case 3: q_delete(q);
					break;
		}
		printf("Displaying queue contents from head to rear\n");
		printf("head=%d rear=%d\n",q->head,q->rear);
		for(j=q->head-1;j>=q->rear;j--)
		{
			printf("q[%d]=%d \n",j,q->arr[j]);	
		}
		printf("Press 1 to abort.\n");
		scanf("%d",&i);
	}
	return 0;
}
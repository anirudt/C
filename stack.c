#include <stdio.h>
#include <malloc.h>

#define MAXSIZE 10

typedef struct 
{
	int arr[MAXSIZE];
	int top;
	/* data */
}stack;


void stack_init(stack *s)
{
	s->top = -1;
}

int push(stack *s)
{
	int n;
	printf("Enter the value you want to be pushed onto the stack\n");
	scanf("%d",&n);
	if(isFull(s))
	{
		printf("The stack is full\n");
		return s->top;
	}
	s->top = s->top + 1;
	s->arr[s->top] = n;
	return s->top;	

}

int isFull(stack *s)
{
	if(s->top==MAXSIZE-1)
		return 1;
	else
		return 0;
}

int isEmpty(stack *s)
{
	if(s->top==-1)
		return 1;
	else
		return 0;
}

int pop(stack *s)
{
	if(s->top==-1)
	{
		printf("Stack is empty\n");
		return s->top;
	}
	printf("Popped element is %d\n",s->arr[s->top]);
	s->top--;
	return s->top;
}

int main()
{
	int top,j;
	int i=0;
	stack *s;
	s = (stack*)malloc(sizeof(stack));
	int choice;
	stack_init(s);
	while(i==0)
	{
		printf("Menu Driven Stack Implementation\n");
		printf("1. Initialize the stack\n");
		printf("2. Push an element\n");
		printf("3. Pop an element from a stack\n");
		printf("Current value of top is %d\n",s->top);
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: stack_init(s);
					break;
			case 2: top = push(s);
					break;
			case 3: top = pop(s);
					break;		
		}
		printf("Printing the current state of the stack, in a top down fashion\n");
		for(j=top;j>=0;j--)
		{
			printf("%d\n",s->arr[j]);
		}
		printf("Want to continue? Press 1 to abort.\n");
		scanf("%d",&i);
	}
	return 0;
}
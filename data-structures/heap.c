#include <stdio.h>
#include <malloc.h>
#define MAXSIZE 15

struct stud
{
	int heap[MAXSIZE];
	int len;
	int *next;
};
typedef struct stud node;

int swap(int *a,int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int right_child(int i)
{
	return 2*i+2;
}

int left_child(int i)
{
	return 2*i+1;
}

int parent(int i)
{
	return ((i-1)/2);
}
//The add function works robustly. Single Add option is there for now.
node *add_term(node *s)
{
	int new,flag2,j;
	j = s->len;
	flag2 = 1;
	printf("Enter the term to be added:\n");
	scanf("%d",&new);
	s->heap[s->len] = new;
	while(flag2>0)
	{
		if(new<=s->heap[parent(j)])
		{
			flag2 = 0;
		}
		else
		{
			swap(&(s->heap[j]), &(s->heap[parent(j)]));
			flag2 = 1;
			j = parent(j);
		}
	}
	return s;
}

node *heapify(node *s)
{
	int j = 0;
	int flag = 1;
	do
	{
		printf("Inside While Loop\n");
		if(s->heap[j]<s->heap[right_child(j)])
		{
			swap(&(s->heap[j]), &(s->heap[right_child(j)]));
			j = right_child(j);
			flag = 1;
		}
		if(s->heap[j]<s->heap[left_child(j)])
		{
			swap(&(s->heap[j]), &(s->heap[left_child(j)]));
			j = left_child(j);
			flag = 1;
		}
		else
			flag=0;
	}while(j!=s->len-1 && right_child(j)!=s->len-1 && left_child(j)!=s->len-1);
	return s;
}

//Deletion always occurs at the root of a heap.
node *delete(node *s)
{
	int n,flag;
	printf("Hello\n");
	swap(&(s->heap[0]),&(s->heap[s->len-1]));
	printf("Hello\n");
	s->heap[s->len-1]=0;
	printf("Hello\n");
	flag = 1;
	while(flag>0)
	{
		if(s->heap[0]<s->heap[1])
		{
			swap(&(s->heap[0]),&(s->heap[1]));
			flag = 1;
		}
		if(s->heap[0]<s->heap[2])
		{
			swap(&(s->heap[0]),&(s->heap[2]));
			flag = 1;	
		}
		else
			flag=0;
	}
	printf("Before heapify\n");
	s = heapify(s);
	return s;
}

node *init_heap(node *s)
{
	free(s);
	s = (node *)malloc(sizeof(node));
	return s;
}


void display(node *s)
{
	int i;
	for(i=0;i<s->len;i++)
	{
		printf("%d \n",s->heap[i]);
	}
}

int main()
{
	int i=0,choice;
	node *s;
	s = (node *)malloc(sizeof(node));
	while(i==0)
	{
		printf("Menu Driven Heap Implementation using a Linked List\n");
		printf("1. Initialize a heap\n");
		printf("2. Add an element to the heap\n");
		printf("3. Delete an element to the heap\n");
		printf("4. Implement heap sort\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: s = init_heap(s);
					s->len = 0;
					break;
			case 2: s = add_term(s);
					s->len++;
					break;	
			case 3: s = delete(s);
					s->len--;
					break;			
		}	
		printf("Hello\n");
		display(s);
		printf("Press 1 to abort. \n");
		scanf("%d",&i);
	}
	return 0;
}

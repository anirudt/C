#include <stdio.h>
#include <malloc.h>

struct stud
{
	int data;
	struct stud *next;
	/* data */
};
typedef struct stud node;

void traverse(node *head)
{
	node *p;
	p = head;
	while(p!=NULL)
	{
		printf("%d \n",p->data);
		p = p->next; 
	}
}

node *create(node *head)
{
	int n,i;
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	node *p;
	for(i=0;i<n;i++)
	{
		if(i==0)
		{
			head = (node *)malloc(sizeof(node));
			p = head;
		}
		else
		{
			p->next = (node *)malloc(sizeof(node));
			p = p->next;
		}
		printf("Enter the data\n");
		scanf("%d",&(p->data));
	}
	p->next = NULL;
	return head;
}

node *delete(node *head)
{
	int k;
	node *p;
	p = head;
	node *q;
	printf("Enter the element to be deleted\n");
	scanf("%d",&k);
	while(p!=NULL && p->data!=k)
	{
		q = p;
		p=p->next;
	}
	if(p==head)
	{
		head = p->next;
	}
	if(p==NULL)
	{
		printf("Reached the end. No element found\n");
	}
	else
	{	
		q->next = p->next;
	}
	return head;
}

node *add(node *head)
{
	int i,k;
	printf("Enter the index data before which is to be added\n");
	scanf("%d",&i);
	printf("Enter the data to be added\n");
	scanf("%d",&k);
	node *p,*q,*new;
	p = head;
	new = (node *)malloc(sizeof(node));
	while(p!=NULL && p->data!=i)
	{
		q = p;
		p = p->next;
	}
	if(p==head)
	{
		new->next = head;
		new->data = k;
	}
	if(p==NULL)
	{
		printf("Found at the end\n");
		q->next=new;
		new->next = NULL;
		new->data = k;
	}
	else
	{
		printf("Found at data point\n");
		q->next = new;
		new->next = p;
		new->data = k;
	}
	return head;
}

int main()
{
	node *head;
	int i = 0;
	int choice;
	head = (node *)malloc(sizeof(node));
	while(i==0)
	{
		printf("Menu Driven Implementation of a Linked List\n");
		printf("1. Creation\n");
		printf("2. Traversing\n");
		printf("3. Adding a node\n");
		printf("4. Deleting a node\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: head = create(head);
					break;
			case 2: traverse(head);
					break;		
			case 3: head = add(head);
					break;
			case 4: head = delete(head);
					break;				
		}
		printf("Press 1 to abort\n");
		scanf("%d",&i);
	}
	return 0;
}
#include <stdio.h>
#include <stdlib.h>

int fact(int n)
{
	if(n==0)
	{
		return 1;
	}
	else
	{
		return n*fact(n-1);
	}
}


int main()
{
	int n,i,*a;
	printf("Enter no. of elements\n");
	scanf("%d",&n);
	a = (int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		a[i] = fact(i);
		printf("a[%d]=%d\n",i,a[i]);
	}
	free(a);
	return 0;
}
#include <stdio.h>
#include <stdlib.h> //since we're using malloc

int main()
{
	int *a, *b, *c;
	int n,i;
	printf("Enter the number of elements in the array\n");
	scanf("%d",&n);
	//we need to use malloc, as we need user defined no. of array elements
	a = (int *)malloc(n*sizeof(int));
	b = (int *)malloc(n*sizeof(int));
	c = (int *)malloc(n*sizeof(int));
	printf("Enter the elements now\n");

	for(i=0;i<n;i++)
	{
		printf("Enter a[%d]=",i);
		scanf("%d",&a[i]);
		printf("Enter b[%d]=",i);
		scanf("%d",&b[i]);
	}

	//Carrying out multiplication 
	for(i=0;i<n;i++)
	{
		c[i] = a[i]*b[i];
		printf("c[%d]=%d\n",i,c[i]);
	}
	free(a);
	free(b);
	free(c);
	return 0;
}
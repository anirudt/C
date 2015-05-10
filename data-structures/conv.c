#include <stdio.h>
#include <stdlib.h>

int main()
{
	double *x,*y,*filter,*coeff;
	int order,n,i,j,k;
	printf("Enter the order of the fliter\n");
	scanf("%d",&order);
	printf("Enter the number of points in the data\n");
	scanf("%d",&n);
	x = (double *)malloc(n*sizeof(double));
	y = (double *)malloc(n*sizeof(double));
	filter = (double *)malloc(order*sizeof(double));
	coeff = (double *)malloc(order*sizeof(double));
	//input initialization block
	for(i=0;i<n;i++)
	{
		x[i] = i;
		y[i] = 0;
	}
	//filter definition block
	for(i=0;i<order;i++)
	{
		filter[i] = 1.0/order;
	}
	k = order-1;
	for(i=0;i<order;i++)
	{
		j = 0;
		while(j>=0 && (i>=j))
		{
			y[i] = y[i] + x[i-j]*filter[j];
			/*
			if(i==order-1)
			{
				coeff[k] = x[i-j]*filter[j];
				k--;
			}
			*/
			j++;
		}
	}
	for(i=order;i<n;i++)
	{
		j = 0;
		while(j<order)
		{
			y[i] = y[i] + filter[j]*x[i-j];
			j++;
		}
	}

	//printing block
	for(i=0;i<n;i++)
	{
		printf("x[%d]=%lf, y[%d]=%lf\n",i,x[i],i,y[i]);
	}
	/*
	for(i=0;i<order;i++)
	{
		printf("c[%d]=%lf\n",i,coeff[i]);
	}
	*/

	return 0;

}

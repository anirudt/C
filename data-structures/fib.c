#include <stdio.h>

int main()
{
	int a,i,b,n,k;
	printf("Enter n:\n");
	scanf("%d",&n);
	a = 0;
	b = 1;
	
	for(i=1;i<=n;i++)
	{	

		if(i==1)
		{
			printf("%d\n",a);
			k = a + b;
			a = b;
			b = k;
			continue;
		}
		if(i==2)
		{
			printf("%d\n",a);
			k = a + b;
			a = b;
			b = k;
			continue;
		}
		k = a + b;
		a = b;
		b = k;
		printf("%d\n",k);
		
	}

	return 0;
}

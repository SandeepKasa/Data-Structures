#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i, temp, j,*a;
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++)
	{
		a[i] = rand()/100000 + 1;
	}
	for (i=0;i<n;i++)
	{
		for (j=i;j<n-1;j++)
		{
			if (a[j]>a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	for (i = 0; i < n ; i++)
		printf("%d  ", a[i]);
	printf("\n");
}

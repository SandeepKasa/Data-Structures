#include <stdio.h>                
#include <stdlib.h>
void countingsort(int [], int, int);
int main()
{
	int num,k = 0;
	scanf("%d",&num);
	int *a;
	a=(int *)malloc(sizeof(int)*num);
	int i;
	int max=0;
	for ( i=0; i<num; i++)
	{
		a[i]=rand()/500000;
		if(a[i]>max)
		{
			max=a[i];
		}

	}
	countingsort(a,max,num);
	return 0;
}
void countingsort(int a[], int max, int num)
{
	int i, j;
	int b[num];
	int *c;
	//int c[max+1];
        c=(int *)calloc(max+1,sizeof(int));
/*	for(i=0;i<max+1;i++)
	{
		c[i]=0;
	}*/
	for(j=0;j<num;j++)
		c[a[j]] = c[a[j]]+1;
	for(i=0;i<max+1;i++)
		c[i] = c[i]+c[i-1];
	for(j=num-1;j>=0;j--)
	{
		b[c[a[j]]-1] = a[j];
		c[a[j]] = c[a[j]]-1;
	}
	for(i=0;i<num;i++)
	{
		printf("%d ",b[i]);
	}
	       printf("\n");
}

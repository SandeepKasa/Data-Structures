#include <stdio.h>
#include <stdlib.h>
int main()
{
	int  num;
	scanf("%d",&num);
	int *arr;
	arr=(int *)malloc(sizeof(int)*num);
	int i,j;
	for (i=0;i<num;i++)
	{
		arr[i]=rand()/500000;
	}
	for(i=1;i<num;i++)
	{
		for(j=i;j>0 && arr[j-1]>arr[j];j--)
		{
			int flag;
			flag=arr[j];
			arr[j]=arr[j-1];
		        arr[j-1]=flag;
		}	
	}
	for(i=0;i<num;i++)
	{
		printf("%d\n",arr[i]);
	}
	return 0;
}

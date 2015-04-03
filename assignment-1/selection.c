#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num;
	scanf("%d",&num);
	int *arr;
	arr=(int *)malloc(sizeof(int)*num);
	int i;
	for (i=0;i<num;i++)
	{
		arr[i] = rand()/500000 ;
	}
	for(i=0;i<num-1;i++)
	{
		int j;
		for(j=i+1;j<num;j++)
		{
			if(arr[i]>arr[j])
			{
				int temp;
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	for(i=0;i<num;i++)
	{
		printf("%d\n",arr[i]);
	}
	      
	       return 0;
}

#include<stdio.h>
#include<stdlib.h>
void mergeSort(long long int [],long long int ,long long int ,long long int );
void partition(long long int [],long long int ,long long int );

int main()
{
	long long int i,n,t;
        long long int *merge;
        scanf("%lld",&n);
	merge=(long long int *)malloc(sizeof(long long int)*n);
	for(i=0;i<n;i++)
        {
		merge[i]=rand()/500000;
	}
	partition(merge,0,n-1);
	for(i=0;i<n;i++)
        {
		printf("%lld ",merge[i]);
	}
	printf("\n");
	return 0;
}

void partition(long long int arr[],long long int low,long long int high)
{

long long int mid,n;

	if(low<high)
        {
		mid=(low+high)/2;
		partition(arr,low,mid);
		partition(arr,mid+1,high);
		mergeSort(arr,low,mid,high);
	}
}

void mergeSort(long long int arr[],long long int low,long long int mid,long long int high)
{
	long long int i,m,k,l,temp[100010],n;

	l=low;
	i=low;
	m=mid+1;

	while((l<=mid)&&(m<=high))
	{
		if(arr[l]<=arr[m])
                {
			temp[i]=arr[l];
			l++;
		}
		else
		{
			temp[i]=arr[m];
			m++;
		}
		i++;
	}

	if(l>mid)
	{
		for(k=m;k<=high;k++)
		{
			temp[i]=arr[k];
			i++;
		}
	}
	else
	{
		for(k=l;k<=mid;k++)
		{
			temp[i]=arr[k];
			i++;
		}
	}

	for(k=low;k<=high;k++)
{
		arr[k]=temp[k];
	}
}

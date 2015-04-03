#include<stdio.h>
int main()
{
	int i,j,N;
	scanf("%d",&N);
	int a[N];
	for(i=0;i<N;i++)
		scanf("%d",&a[i]);
	qsort(a,0,N-1);
	for(i=0;i<N-1;i++)
           printf("%d ",a[i]);
	printf("%d\n",a[N-1]);
}

void qsort(int a[],int first,int last)
{
	int i,j,k,pointer;
	if(first<last)
	{
	pointer=first;
	i=first;
	j=last;
	while(i<j)
	{
		while(a[pointer]>=a[i])
			i++;
		while(a[pointer]<a[j])
			j--;
		if(i<j)
		{
                    k=a[i];
		    a[i]=a[j];
		    a[j]=k;
		}
	}
	k=a[j];
	a[j]=a[pointer];
	a[pointer]=k;
	qsort(a,first,j-1);
	qsort(a,j+1,last);
	}
}
    

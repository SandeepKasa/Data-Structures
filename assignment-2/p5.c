#include<stdio.h>
#include<stdlib.h>
int cmpfunc (const void * a, const void * b)
{
	   return ( *( int*)a - *( int*)b );
}

int main()
{
         int n,i,z,k,j,l,t;
	scanf("%d",&t);
	while(t--)
	{
	scanf("%d",&n);
	 int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	qsort(a,n,sizeof(int),cmpfunc);
//	for(i=0;i<n;i++)
//	{
//		printf("%d ",a[i]);
//	}
//	      printf("\n");
         int count=0,flag=0;
	scanf("%d",&k);
	j=0;
	z=0;
	
	
	//	printf("Halou\n");
		
		for(;z!=n-1;)
		{
		//	printf("Yes\n");
			
			
			
			
			if(a[j]!=0)
			{
				flag++;
			}
			if(flag==k)
			{
				z++;
				flag=0;
				a[j]=0;
				
			}
j++;
if(j==n)
j=0;
		
		
		
			
		
//	printf("z= %d\n",z);
		
		
		//	printf("z= %lld\n",z);
	
		
            
	}	
	for(i=0;i<n;i++)
	{
		if(a[i]!=0)
		{
			printf("%d\n",a[i]);
		}
	}
	}
	return 0;
}

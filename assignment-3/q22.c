#include<stdio.h>
int main()
{
	int n,a,b,c,i,N;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d",&N,&a,&b);
		if(a==b)
			printf("%d\n",a);
		else if(a!=b)
		{
			while(a!=b)
			{
				if(a>b)
				{
					if(a%2==0)
						a=a/2;
					else
						a=(a-1)/2;
				}
				else if(a<b)
				{
					if(b%2==0)
						b=b/2;
					else
						b=(b-1)/2;
				}
				if(a==b)
					printf("%d\n",a);

			}
		}
	}
	return 0;
}




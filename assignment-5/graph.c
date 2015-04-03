#include<stdio.h>
#include<stdlib.h>
int count,top,bottom;
int *stack;
int depth_fs(int **,int *,int,int);
int main()
{
	int t,temp;
	int **adjacent,*visit;
	scanf("%d",&t);
	while(t--)
	{
		int flag=0;
		top=0;
		bottom=1;
		int out=0;
		int i,j,n;
		temp=0;
		scanf("%d",&n);
		adjacent=(int **)malloc(sizeof(int *)*n);
		visit=(int *)calloc(n,sizeof(int));
		stack=(int *)malloc(sizeof(int)*n);
		for(i=0;i<n;i++)
		{
			adjacent[i]=(int *)malloc(sizeof(int)*n);
			for(j=0;j<n;j++)
			{
				scanf("%d",&adjacent[i][j]);
				//	printf("%d\n",adjacent[i][j]);
			}

		}

		//	printf("%d\n",adjacent[2][1]);
		//	scanf("%d",&v);
		//	key++;
		//	queue[key]=v;

		for(temp=0;temp!=-1;)
		{
			count=1;
			flag=0;
		//	printf("Halou\n");
			top=0;
			bottom=1;
			visit[temp]=1;
			stack[top]=temp;
			depth_fs(adjacent,visit,temp,n);
			if(count>out)
			{
				out=count;
			}
			for(i=0;i<n;i++)
			{
				if(visit[i]==0)
				{
					flag=1;
					temp=i;
				}
			}
			if(flag!=1)
			{
				temp=-1;
			}
		//	printf("1%d\n",temp);

		}
		printf("%d\n",out);
	}
	return 0;
}
int depth_fs(int **adjacent,int *visit, int temp,int n)
{
	if(top>=bottom)
		return;
	int j;
	for(j=0;j<n;j++)
	{
	//	printf("Halou\n");
		if(adjacent[temp][j]==1 && j!=temp && visit[j]==0)
		{
			printf("Halou\n");
			visit[j]=1;
			count++;
			stack[bottom++]=j;
			depth_fs(adjacent,visit,temp,n);
		}
	}
	printf("1 %d\n",count);
	bottom = bottom - 1;
}





#include<stdio.h>
#include<stdlib.h>
int **adjacent,*visit,*queue;
int n,f=0,r=-1,k=0;
void bfs(int v)
{
	int j;
	for(j=1;j<=n;j++)
	{
                if(adjacent[v][j]==1 && visit[j]!=1 &&v!=j)
		{
			queue[++r]=j;
	//		visit[j]=1;
		}
	}
	if(f<=r)
	{
		visit[queue[f]]=1;
		bfs(queue[f++]);
	}
}
int put_value(int v)
{
	int j;
	k=0;
	int l;
	for(j=1;j<=n;j++)
	{
		visit[j]=0;
	}
	bfs(v);
        for(l=1;l<=n;l++)
        {
	if(visit[l]==1)
	{
		k++;
	}
        }
        return k;
}

int main()
{
	int i,j,t;
	scanf("%d",&t);
	while(t--)
	{
        f=0,r=-1,k=0;
        int v,main=1;
	scanf("%d",&n);
	adjacent=(int **)malloc(sizeof(int *)*(n+1));
	visit = (int *)calloc(n+1,sizeof(int));
	queue=(int *)malloc(sizeof(int)*(2*n+5));
	for(i=1;i<=n;i++)
	{
		adjacent[i]=(int *)malloc(sizeof(int)*(n+1));
		for(j=1;j<=n;j++)
		{
			scanf("%d",&adjacent[i][j]);
		}
	}
	for(i=1;i<=n;i++)
	{
		f=0;
		r=-1;
                  if(visit[i]!=1)
		{
			v=put_value(i);
			if(v>main)
			{
				main=v;
			}
		}
	}
//	printf("Halou\n");
        printf("%d\n",main);
	}
	return 0;
}

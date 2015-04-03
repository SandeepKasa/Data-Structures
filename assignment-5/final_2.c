#include<stdio.h>
#include<stdlib.h>
struct node
{
	int value;
	int tstr;
	int tfin;
	int st;
};
int time,ad[1000][1000];
int vn;
struct node *a;
int cmp(const void *a,const void *b)
{
	return (((struct node*)b)->tfin-((struct node *)a)->tfin);
}
void dfs(int);
void dfs_visit(int);
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		time=1;
		int en,va,vb;
		int count=0;
		scanf("%d %d",&vn,&en);
		a=(struct node *)calloc(vn,sizeof(struct node));
		int i,j;
		for(i=0;i<vn+3;i++)
			for(j=0;j<vn+3;j++)
				ad[i][j]=0;
	        while(en--)
		{
			scanf("%d %d",&va,&vb);
			ad[va][vb]=1;
		}
		for(i=0;i<vn;i++)
		{
			a[i].st=-1;
			a[i].value=i;
		}
		for(i=0;i<vn;i++)
		{
			if(a[i].st==-1)
			{
				a[i].st=0;
				a[i].tstr=time++;
				dfs(i);
			}
		}
		qsort(a,vn,sizeof(struct node),cmp);
		for(i=0;i<vn;i++)
		{
			a[i].st=-1;
		}
		for(i=0;i<vn;i++)
		{
			if(a[i].st==-1)
			{
				a[i].st=0;
				dfs_visit(a[i].value);
				count++;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
void dfs(int v)
{
	int i=0;
	while(i<vn)
	{
		if(ad[v][i]==1)
		{
			if(a[i].st==-1)
			{
				a[i].st=0;
				a[i].tstr=time++;
				dfs(i);
			}
		}
		i++;
	}
	a[v].st=1;
	a[v].tfin=time++;
	return;
}
void dfs_visit(int v)
{
	int i=0;
	int k;
	int j;
	while(i<vn)
	{
		if(ad[i][v]==1)
		{
			for(j=0;j<vn;j++)
			{
				if(a[j].value==i)
					k=j;
			}
                        if(a[k].st==-1)
			{
				a[k].st=0;
				dfs_visit(i);
			}
		}
		i++;
	}
	a[k].st=1;
	return;
}



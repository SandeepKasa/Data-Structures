#include<stdio.h>
#include<stdlib.h>
int stack[1000],ind=0;
int time=1;
void push(int el)
{
	stack[ind]=el;
	ind++;
}
int pop()
{
	int tmp;
	tmp=stack[ind-1];
	ind--;
	return tmp;
}
void dfs(int v,int vn)
{
	for(i=0;i<vn;i++)
	{
		if(adj[v][i]==1)
		{
			if(visit[v]==0)
				{
					push(i);
					state[i]=1;
					timed[i]=time++;
					dfs(i);
				}
		}
	}
	state[v]=1;
	timef[v]=time++;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&vn,&en);
		for(j=0;j<en;j++)
		{
			scanf("%d %d",&v1,&v2);
			adj[v1][v2]=1;
		}


	



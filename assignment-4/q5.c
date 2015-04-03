#include<stdio.h>
#include<stdlib.h>
int n1=1,n2=1;
void insert_max(int a[],int ind)
{
	int par,temp;
	par=ind/2;
	while (ind>1)
	{
		if (a[par]<a[ind])
		{
			temp=a[ind];
			a[ind]=a[par];
			a[par]=temp;
		}
		ind=par;
		par=ind/2;
	}
}
void insert_min(int a[],int ind)
{
	int par,temp;
	par=ind/2;
	while(ind>1)
	{
		if(a[par]>a[ind])
		{
			temp=a[ind];
			a[ind]=a[par];
			a[par]=temp;
		}
		ind = par;
		par=ind/2;
	}
}
void delete_max(int a[])
{
	int l,r,i,temp,parent;
	i=1;
	a[1] = a[n1 - 1];
	n1 = n1 - 1;
	l = 2 * i ; 
	r = (2 * i) + 1; 
	while(5)
	{
		if((r<=n1))
		{
			if (a[i] < a[l] || a[i] < a[r])
			{
				if (a[l] > a[r])
				{
					temp = a[i];
					a[i] = a[l];
					a[l] = temp;
					i = l;
					l=2*i;
					r=(2*i)+1;
				}
				else
				{
					temp = a[i];
					a[i] = a[r];
					a[r] = temp;
					i = r;
					r=(2*i)+1;
					l=(2*i);
				}
			}
			else
			{
				break;
			}
		}
		else
		{
			if(l<=n1)
			{
				if ( a[i]<a[l])    
				{
					temp = a[i];
					a[i] = a[l];
					a[l] = temp;
					i=l;
					l=(2*i);
					r=(2*i)+1;
				}
				else
					break;
			}
		}
		if(l>n1 && r>n1)
			break;
	}
}

void delete_min(int a[])
{
	int l,r,i,temp,parent;
	i=1;
	a[1] = a[n2 - 1];
	n2 = n2 - 1;
	l = 2 * i ;
	r = (2 * i) + 1;
	while(5)
	{
		if((r<=n2))
		{
			if (a[i] > a[l] || a[i] > a[r])
			{
				if (a[l] < a[r])
				{
					temp = a[i];
					a[i] = a[l];
					a[l] = temp;
					i = l;
					l=2*i;
					r=(2*i)+1;
				}
				else
				{
					temp = a[i];
					a[i] = a[r];
					a[r] = temp;
					i = r;
					r=(2*i)+1;
					l=(2*i);
				}
			}
			else
			{
				break;
			}
		}
		else
		{
			if(l<=n2)
			{
				if ( a[i]>a[l])
				{
					temp = a[i];
					a[i] = a[l];
					a[l] = temp;
					i=l;
					l=(2*i);
					r=(2*i)+1;
				}
				else
					break;
			}
		}
		if(l>n2 && r>n2)
			break;
	}
}



	
int main()
{
	int i,n,p,k=0,num,j,count=0,u;
	scanf("%d",&n);
	int max[(3*n/4)+5];
	int min[(n/4)+5];
	for(i=1;i<=n;i++)
	{
		scanf("%d",&p);
		if(p==2 && k<4)
		{
			scanf("%d",&u);
			count++;
			if((count%4)!=0)
			{
				max[n1]=u;
				insert_max(max,n1);
				n1++;
                        }
			else if((count%4)==0)
			{
				if(u>=max[1])
				{
			             min[n2]=u;
				insert_min(min,n2);
				n2++;
				}
				else
				{
					min[n2]=max[1];
					insert_min(min,n2);
					n2++;
					delete_max(max);
					max[n1]=u;
					insert_max(max,n1);
					n1++;
				}
			}
			k++;
		}
		else if(p==2 && k>=4)
		{
			scanf("%d",&u);
			count++;
			if((count%4)!=0)
			{
				if(u>min[1])
				{
					max[n1]=min[1];
					insert_max(max,n1);
					n1++;
					delete_min(min);
					min[n2]=u;
					insert_min(min,n2);
					n2++;
				}
				else
				{
					max[n1]=u;
					insert_max(max,n1);
						n1++;
				}
			}
			else if((count%4)==0)
			{
				if(u>max[1])
				{
					min[n2]=u;
					insert_min(min,n2);
					n2++;
				}
				else
				{
					min[n2]=max[1];
					insert_min(min,n2);
					n2++;
					delete_max(max);
					max[n1]=u;
					insert_max(max,n1);
					n1++;
				}
			}
		}
                   else if(p==1)
		 {
			if(count==0 || k<4)
			{

				printf("-1\n");
			}
			else
			{
				printf("%d\n",min[1]);
			}
		}
	}
	return 0;
}
					


		
	

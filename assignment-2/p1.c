#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
	char str[51];
	struct node *next;
};
struct node *link1[10],*link2[10];
char head[100000][51];
void display(long long int );
void enqueue(long long int ,char []);
char *dequeue(long long int );
void push_into_array(long long int ,long long int);
void pop_from_array();
int main()
{
	long long int i;
	long long int t;
	scanf("%lld",&t);
	while(t--)
	{
		long long int n,j;
		scanf("%lld",&n);
		for(j=0;j<n;j++)
		{
		//	printf("Yes\n");
			long long int len;
			long long int var;
			char str[51];
			scanf("%s",str);
			len=strlen(str);
			var=str[(len-1)];
			var=var-48;
			enqueue(var,str);
		}
		long long int pass;
		scanf("%lld",&pass);
		pass=pass-1;
		long long int iteration=2;
		while(pass!=0)
		{
		//	printf("1Halou\n");
			pop_from_array();
			push_into_array(iteration,n);
			iteration=iteration+1;
			pass=pass-1;
		}
		display(n);
	}
	return 0;
}

void display(long long int n)
{
	long long int i,j=0;
	for(i=0;i<=9;i++)
	{
//		printf("1Yes\n");
		while(link1[i]!=NULL)
		{
		//	printf("Halou\n");
			if(j!=n-1)
			{
				printf("%s ",link1[i]->str);
			}
			if(j==n-1)
			{
				printf("%s\n",link1[i]->str);
			}
			j++;
			link1[i]=link1[i]->next;
		}
	}
	return ;
}
void enqueue(long long int i,char s[])
{
	struct node *temp2;
	temp2=(struct node *)malloc(sizeof(struct node));
	strcpy(temp2->str,s);
	temp2->next=NULL;
	if(link1[i]==NULL)
	{
		link2[i]=temp2;
		link1[i]=temp2;
	}
	else
	{
		link2[i]->next=temp2;
		link2[i]=temp2;
	}
	return ;
}
char *dequeue(long long int i)
{
	char *temp3;
	temp3=(char *)malloc(sizeof(char)*51);
	if(link1[i]==NULL)
		return;
	else
	{
		strcpy(temp3,link1[i]->str);
		struct node *temp4;
		temp4=link1[i];
		link1[i]=link1[i]->next;
		free(temp4);
		return temp3;
	}
}
void push_into_array(long long int temp,long long int n)
{
	long long int i;
	long long int len,flag;
	for(i=0;i<n;i++)
	{
	//	printf("3Halou\n");
		char str_2[51];
		len=strlen(head[i]);
		strcpy(str_2,head[i]);
	//	printf("%s\n",str_2);
		if((len-temp)>=0)
		{
			flag=str_2[(len-temp)];
		//	printf("%lld\n",flag);
			flag=flag-48;
		}
		else
		{
			flag=0;
		}
		enqueue(flag,str_2);
	}
	return ;
}
void pop_from_array()
{
	long long int i=0,j=0;
	while(i<=9)
	{
	//	printf("4Halou\n");
		while(link1[i]!=NULL)
		{
	//		printf("5Halou\n");
			strcpy(head[j],dequeue(i));
			j++;
		}
		link1[i]=NULL;
		link2[i]=NULL;
		i++;
	}
	return ;
}



#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int tail=0;
char infix[1000];
char prefix[1000];
void push(char c)
{
	int i;
	i=tail;
	infix[i]=c;
	i++;
	tail=i;
}
int pop(void)
{
	char data;
	if(infix[tail-1]=='\0')
	{
		return -1;
	}
	else
	{
		data=infix[tail-1];
		infix[tail-1]='\0';
		tail--;
	}
	return data-'0';
}
int main()
{
	char str[110];
	int len,i,t;
	char c;
	char out1,out2,final;
	scanf("%d",&t);
	int count=0;
	while(t--)
	{
		count=0;
		scanf("%s",str);
		len=strlen(str);
		int count1=0,count2=0;
		int state=0;
		for(i=0;i<len;i++)
		{
			if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/' || str[i]=='^')
			{
				count1++;
			}
			else
			{
				count2++;
			}
		}
		int flag=0;
		if(count2==count1+1)
		{
			//printf("%s l%dl",str,len);
			for(i=len-1;i>=0;i--)
			{
				//printf("%c\n",str[i]);
				if(str[i]>='0' && str[i]<='9')
				{
					c=str[i];
					count++;
					push(c);
				}
				else if(str[i]=='+')
				{
					if(count<2)
					{
						state=1;
						printf("invalid\n");
						break;
					}
					else
					{
						out1=pop();
						out2=pop();
						final=out1+out2;
						push(final+'0');
						count--;
					}
				}
				else if(str[i]=='-')
				{
					if(count<2)
					{
						state=1;
						printf("invalid\n");
						break;
					}
					else
					{

						out1=pop();
						out2=pop();
						final=out1-out2;
						push(final+'0');
						count--;
					}
				}
				else if(str[i]=='*')
				{
					if(count<2)
					{
						state=1;
						printf("invalid\n");
						break;
					}
					else
					{


						out1=pop();
						//	printf("%d\n",out1);
						out2=pop();
						//	printf("%d\n",out2);
						final=out1*out2;
							//printf("%d\n",final);
						push(final+'0');
						count--;
					}
				}
				else if(str[i]=='/')
				{
					if(count<2)
					{
						state=1;
						printf("invalid\n");
						break;
					}
					else
					{


						out1=pop();
						out2=pop();
						if(out2==0)
						{
							state=1;
							printf("invalid\n");
						}
						else
						{
							flag=1;
							final=out1/out2;
							push(final+'0');
						}
						count--;
					}

				}
				else if(str[i]=='^')
				{
					if(count<2)
					{
						state=1;
						printf("invalid\n");
						break;
					}
					else
					{


						out1=pop();
						out2=pop();
						//	printf("%d\n",out1);
						//	printf("%d\n",out2);
						final=pow(out1,out2);
						push(final+'0');
						//printf("%d\n",infix[0]-'0');

						count--;
						//	printf("l %d\n",final);
					}
				}
				else
				{
					state=1;
					printf("invalid\n");
					break;
				}
			}
			if(state!=1)
			{
				//printf("%d\n",tail);
				printf("%d\n",infix[0]-'0');
				pop();
			}
		}
		else
		{
			printf("invalid\n");
		}
	}
	return 0;
}

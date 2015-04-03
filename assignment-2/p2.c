#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int tail=0;
char infix[1000];
char prefix[1000];
int j=0;
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
		tail--;
	}
	return data;
}
void operator(char c)
{
	int out;
	if(infix[tail-1]=='\0' || infix[tail-1]==')')
	{
		push(c);
	}
	else
	{
		if(c=='(')
		{
			while(infix[tail-1]!=')')
			{
				out=pop();
				prefix[j]=out;
				j++;
			}
			pop();
		}
		else
		{
			if(c=='+'|| c=='-')
			{
			//	while(b[last-1]!='\0')
			//	{
			//		printf("Halou\n");
				        while(infix[tail-1]=='*' || infix[tail-1]=='/' || infix[tail-1]=='^')
					{
					out=pop();
					prefix[j]=out;
				        j++;
					}
			
			//	}
					push(c);
			}
			else if(c=='*' || c=='/')
			{
				if(infix[tail-1]=='+' || infix[tail-1]=='-' || infix[tail-1]=='*' || infix[tail-1]=='/')
					push(c);
				else
				{
						while(infix[tail-1]=='^')
						{
							out=pop();
							prefix[j]=out;
							j++;
						}
					push(c);
				}
			}
			else if(c=='^')
			{
				while(1)
                                {
					//printf("Halou\n");
					if(infix[tail-1]=='^')
					{
					out=pop();
					prefix[j]=out;
					j++;
					}
					else
					{
						break;
					}
				}
				push(c);
			}
			else
			{
				push(c);
			}

		}
	}

}
int main()
{
	int t,len,i;
	scanf("%d",&t);
	while(t--)
	{
		j=0;
	char str[1000];
	int count=0,flag=0,flag1=0,flag2=0;
	for(i=0;i<1000;i++)
	{
		prefix[i]=0;
	}
	int out;
	scanf("%s",str);
	len=strlen(str);
	if(str[0]=='+' || str[0]=='-' || str[0]=='*' || str[0]=='/' || str[0]=='^' || str[len-1]=='+' || str[len-1]=='-' || str[len-1]=='*' || str[len-1]=='/' || str[len-1]=='^')
	{
		printf("invalid\n");
		continue;
	}
	{
	for(i=len-1;i>=0;i--)
	{
		if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/' || str[i]=='^')
		{
			if(count==1)
			{
				printf("invalid\n");
				count=0;
				flag=1;
				break;
			}
			operator(str[i]);
			count++;
		}
		else if(str[i]==')')
		{
			operator(str[i]);
			flag1++;
		}
		else if(str[i]=='(')
		{
			operator(str[i]);
			flag2++;
			if(flag2>flag1)
			{
				printf("invalid\n");
			        flag=1;
				break;
			}
		}
                 else if(str[i]>='0' && str[i]<='9')
		{
			prefix[j]=str[i];
			j++;
			count=0;
		}
		else
		{
			printf("invalid\n");
			flag=1;
			break;
		}
	}
	while(str[tail-1]!='\0')
	{
		out=pop();
		prefix[j]=out;
		j++;
	}
	if(flag!=1 && flag1!=flag2)
	{
		printf("invalid\n");
		continue;
	}
	if(flag!=1)
	{
        for(i=len-1;i>=0;i--)
	{
		if(prefix[i]!=')' && prefix[i]!='(')
		printf("%c",prefix[i]);
	}
     printf("\n");
	}
	}
	
	}
	return 0;
}



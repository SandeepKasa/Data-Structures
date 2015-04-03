#include<stdio.h>
#include<stdlib.h>
struct node
{
	int value;
	int sum;
};
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i,num,j,flag=0,count=0,k,flag1=0;
		scanf("%d",&num);
		struct node a[100000],b[100000];
		for(i=0;i<num;i++)
		{
                  scanf("%d",&a[i].value);
		  a[i].sum=0;
		  b[i].value=0;
		  b[i].sum=0;
		}
		b[0].value=a[0].value;
		i=1;
		j=1;
                if(b[0].value>0)
               {
                  printf(":-( Try again.\n");
               }
               else
               {
		while(i<num)
		{
                        if(a[i].value>0)
                        {
                            for(k=0;k<j;k++)
                            {
                               if(abs(b[k].value)==a[i].value)
                               {
                                   flag1=0;
                                   break;
                               }
                               else
                               {
                                  flag1=1;
                               }
                            }
                               if(flag1==1)
                             {
                                  printf(":-( Try again.\n");
                                  break;
                             }
                        }
                              if(j==0 && i<num)
                        {
                          printf(":-( Try again.\n");
                          flag=1;
                          break;
                        }

                       
                        if(abs(a[i].value)>abs(b[j-1].value))
			{
				flag=1;
				printf(":-( Try again.\n");
				break;
			}
			else if(abs(a[i].value)==abs(b[j-1].value))
			{
				b[j-1].value=0;
				b[j-1].sum=0;
				if(j!=1)
				{
				b[j-2].sum=b[j-2].sum+(abs(a[i].value));
				if(b[j-2].sum>=abs(b[j-2].value))
				{
					flag=1;
					//printf("%d %d %d %d\n",b[j-2].sum,abs(b[j-2].value),j-2,i);
					printf(":-( Try again.\n");
					break;
				}
				}
                                j--;
			}
			else
			{
				b[j].value=a[i].value;
				j++;
			}
			i++;

		}
           
	         if(flag!=1 && flag1!=1)
		 {
			 for(i=0;i<num;i++)
			 {
				 if(b[i].value!=0)
				 {
					 printf(":-( Try again.\n");
					 break;
				 }
				 else
				 {
					 count++;
				 }
			 }
			 if(count==num)
			 {
				 printf(":-) Matrioshka!\n");
			 }
		 }
}
      
            }
	return 0;
}
		





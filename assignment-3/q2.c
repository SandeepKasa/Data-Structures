#include<stdio.h>
#include<stdlib.h>
int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
	   int n,p,q,temp;
	   scanf("%d %d %d",&n,&p,&q);
	   if(p==q)
	   {
		   printf("%d\n",p);
	   }
           else
	   {
		   if(p>q)
		   {
			   temp=p;
			   p=q;
			   q=temp;
		   }
	   while(q!=0)
	   {
		   q=q/2;
		   if(p==q)
		   {
			   printf("%d\n",p);
			   break;
		   }
		   else if(q<p)
		   {
			   p=p/2;
			   if(p==q)
			   {
				   printf("%d\n",p);
				   break;
			   }
		   }
	   }
	   }
   }
   return 0;
}

#include<stdio.h>
#include<stdlib.h>
struct node
{
	int coff;
	int expo;
	struct node *next;
};
struct node *insert_sort(struct node *poly,int coef,int expo)
{
        if(coef==0)
                return poly;
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp->expo = expo;
        temp->coff = coef;
        temp->next = NULL;
        if(poly == NULL)
                return temp;
        struct node* start = poly;
        struct node* prev = NULL;
        while(poly!=NULL)
        {
                if(poly->expo<temp->expo)
                        break;
                if(poly->expo == temp->expo)
                {
                        poly->coff = poly->coff+temp->coff;
                        return start;
                }
                prev = poly;
                poly = poly->next;
        }
        if(prev == NULL)
        {
                temp->next = poly;
                return temp;
        }
        else if(poly==NULL)
                prev->next=temp;
        else
        {
                temp->next = poly;
                prev->next = temp;
        }
        return start;
}

struct node *insert(struct node *poly,int coef,int expo)
{
	struct node *ptr,*temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->coff=coef;
	temp->expo=expo;
	if(poly==NULL)
	{
		temp->next=poly;
		poly=temp;
	}       
	else    
	{
		ptr=poly;
		while(ptr->next!=NULL)
			ptr=ptr->next;
		temp->next=ptr->next;
		ptr->next=temp;
	}
	return poly;
}
struct node *construct(struct node *poly,int n)
{
	int i,expo;
	int coff;
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&expo,&coff);
		poly=insert_sort(poly,coff,expo);
	}
	return poly;
}
void display(struct node *temp)
{
	int count=0;
	struct node *temp2;    
	temp2=temp;
	while(temp!=NULL)
	{
		if(temp->coff!=0)
		{
		count++;
		}
		temp=temp->next;    
	}
             printf("%d\n",count);
	while(temp2!=NULL)
	{
		if(temp2->coff!=0)
		{
		printf("%d %d\n",temp2->expo,temp2->coff);
		}
		temp2=temp2->next;
	}
}
void poly_add(struct node *poly1,struct node *poly2)
{
	struct node *poly3;
	poly3=NULL;
	while(poly1!=NULL && poly2!=NULL)
	{
		if(poly1->expo > poly2->expo)
		{
			poly3=insert_sort(poly3,poly1->coff,poly1->expo);
			poly1=poly1->next;
		}
		else if(poly2->expo > poly1->expo)
		{
			poly3=insert_sort(poly3,poly2->coff,poly2->expo);
			poly2=poly2->next;
		}       
		else if(poly1->expo==poly2->expo)
		{
			poly3=insert_sort(poly3,poly1->coff+poly2->coff,poly1->expo);
			poly1=poly1->next;
			poly2=poly2->next;
		}
	}
	while(poly1!=NULL)
	{
		poly3=insert_sort(poly3,poly1->coff,poly1->expo);
		poly1=poly1->next;
	}
	while(poly2!=NULL)
	{
		poly3=insert_sort(poly3,poly2->coff,poly2->expo);
		poly2=poly2->next;
	}
	display(poly3);
}

void poly_sub(struct node *poly1,struct node *poly2)
{
	struct node *poly3;
	poly3=NULL;
	while(poly1!=NULL && poly2!=NULL)
	{
		if(poly1->expo > poly2->expo)
		{
			poly3=insert_sort(poly3,poly1->coff,poly1->expo);
			poly1=poly1->next;
		}
		else if(poly2->expo > poly1->expo)
		{
			poly3=insert_sort(poly3,-(poly2->coff),poly2->expo);
			poly2=poly2->next;
		}
		else if(poly1->expo==poly2->expo)
		{
			poly3=insert_sort(poly3,(poly1->coff)-(poly2->coff),poly1->expo);
			poly1=poly1->next;
			poly2=poly2->next;
		}
	}
	while(poly1!=NULL)
	{
		poly3=insert_sort(poly3,poly1->coff,poly1->expo);
		poly1=poly1->next;
	}
	while(poly2!=NULL)
	{
		poly3=insert_sort(poly3,poly2->coff,poly2->expo);
		poly2=poly2->next;
	}
	display(poly3);
}
void poly_mult(struct node *poly1, struct node *poly2)
{
	struct node *poly2_temp = poly2;
	struct node *poly3=NULL;
	struct node *start=NULL;
	int out,final=0;
	int flag1,flag2;
	while(poly1!=NULL)
	{
		poly2=poly2_temp;
		while(poly2!=NULL)
		{
		/*	flag1=poly1->coff*poly2->coff;
                        flag2=poly1->expo+poly2->expo;
			if(start==NULL)
			{
				start = (struct node *)malloc(sizeof(struct node));
				start->coff = flag1;
				start->expo=flag2;
				start->next=NULL;
				poly3=start;

			}*/
                       /* else
			{
			poly3 = start;
			while(poly3->next)
			{
				printf("%d\n",poly3->coff);
				poly3=poly3->next;
			}
			while(poly3!=NULL)
			{
				if(poly3->expo == flag2)
				{
					poly3->coff=poly3->coff+flag1;
				}
				else
				{
					poly3=insert_sort(start,flag1,flag2);
				}
				poly3=poly3->next;
				printf("%d\n",poly3->coff);
			
			}*/
			poly3=insert_sort(poly3,poly1->coff*poly2->coff,poly1->expo+poly2->expo);
		        poly2=poly2->next;
		}
	        poly1=poly1->next;
	}
//	poly3=start;
//	printf("a\n");
	display(poly3);
}       


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	struct node *poly1=NULL;
	struct node *poly2=NULL;
//	struct node *poly3=NULL;
	int m,n;
	scanf("%d %d",&m,&n);
	poly1=construct(poly1,m);
	poly2=construct(poly2,n);
//	display(poly1);
//	display(poly2);
	poly_add(poly1,poly2);
	poly_sub(poly1,poly2);
	poly_mult(poly1,poly2);
	}
	return 0;
}


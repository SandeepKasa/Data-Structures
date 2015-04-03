#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* lchild;
	struct node* rchild;
};

int min(int [],int ,int);
struct node* cinsert(int [],int,int); 
void preorder(struct node* ,struct node*);
void postorder(struct node* ,struct node*);
int main()
{
	int n,i,t;
	scanf("%d",&t);
	while(t--)
	{
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	struct node *root;
	root =	cinsert(a,0,n-1);
	if(root!=NULL)
	{
		printf("%d",root->data);
	}
	preorder(root,root);
	printf("\n");
	postorder(root,root);
	if(root!=NULL)
	{
		printf("%d",root->data);
	}
	printf("\n");
/*	postorder(root,root);
	printf("\n");*/
	}
	return 0;
}
int min(int a[],int top,int bottom)
{
	int minimum=a[top];
	int minimum_key=top;
	int i;
	for(i=top+1;i<=bottom;i++)
	{
		if(a[i]<minimum)
		{
			minimum=a[i];
			minimum_key=i;
		}
	}
                  return minimum_key;
}
struct node* cinsert(int a[],int top,int bottom)
{
       int key;
       if(top>bottom)
       {
	       return NULL;
       }

       key=min(a,top,bottom);
       struct node *temp=(struct node* )malloc(sizeof(struct node));
       temp->data=a[key];
       temp->lchild=NULL;
       temp->rchild=NULL;
       if(top==bottom)
       {
	       return temp;
       }

       temp->lchild = cinsert(a,top,key-1);
       temp->rchild=  cinsert(a,key+1,bottom);

       return temp;
}
void preorder(struct node *root,struct node *r)
{
	if(root==NULL)
		return ;
	if(root!=r)
	{
	printf(" %d",root->data);
	}
	preorder(root->lchild,r);
	preorder(root->rchild,r);
}
void postorder(struct node *root,struct node *r)
{
	if(root==NULL)
		return ;
	postorder(root->lchild,r);
	postorder(root->rchild,r);
	if(root!=r)
	{
          printf("%d ",root->data);
	}
}

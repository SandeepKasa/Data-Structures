#include<stdio.h>
#include<stdlib.h>
int key=0;
int count=0;
struct node *rotate_right(struct node *);
struct node *rotate_left(struct node *);
struct node
{
	int data;
	struct node *lchild;
	struct node *rchild;
};
struct node *insert(struct node *root,int value)
{
	if(root==NULL)
	{
	   struct node *temp=(struct node *)malloc(sizeof(struct node));
	   temp->data=value;
	   temp->lchild=NULL;
	   temp->rchild=NULL;
	   return temp;
	}
	else if(value < root->data)
	{
		root->lchild=insert(root->lchild,value);
	}
	else if(value > root->data)
	{
		root->rchild=insert(root->rchild,value);
	}
	return root;
}
struct node *search(struct node *root,int value)
{
	if(root==NULL)
		return NULL;
	else if(root->data>value) 
	{
		root->lchild=search(root->lchild,value);
		root=rotate_right(root);
	}
	else if(root->data<value)
	{
		root->rchild=search(root->rchild,value);
		root=rotate_left(root);
	}
		return root;
}
struct node *rotate_right(struct node *ptr)
{
	struct node *temp;
	temp=ptr->lchild;
	ptr->lchild=temp->rchild;
	temp->rchild=ptr;
	return temp;
}
struct node *rotate_left(struct node *ptr)
{
	struct node *temp;
	temp=ptr->rchild;
	ptr->rchild=temp->lchild;
	temp->lchild=ptr;
	return temp;
}
void in_order(struct node *root)
{
	if(root==NULL)
		return ;
	in_order(root->lchild);
	if(count==0)
	{
	printf("%d",root->data);
	count=1;
	}
	else
	{
		printf(" %d",root->data);
	}
        in_order(root->rchild);
}
void pre_order(struct node *root)
{
	if(root==NULL)
		return ;
	if(count==0)
	{
		printf("%d",root->data);
		count=1;
	}
	else
	{
		printf(" %d",root->data);
	}
	pre_order(root->lchild);
	pre_order(root->rchild);
}
void post_order(struct node *root)
{
	if(root==NULL)
		return ;
	post_order(root->lchild);
	post_order(root->rchild);
	if(count==0)
	{
		printf("%d",root->data);
		count=1;
	}
	else
	{
		printf(" %d",root->data);
	}
}
int main()
{
	int t,i;
	scanf("%d",&t);
	while(t--)
	{
		key=0;
		count=0;
		int n;
		int r;
		scanf("%d",&n);
		int u,v;
		struct node *root=NULL;
		for(i=0;i<n;i++)
		{
			scanf("%d",&u);
			root=insert(root,u);
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&v);
		}
//		in_order(root);
//		printf("\n");
		scanf("%d",&r);
		root=search(root,r);
		in_order(root);
                printf("\n");
		count=0;
		pre_order(root);
                printf("\n");
		count=0;
		post_order(root);
		printf("\n");
	}
	return 0;
}



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
struct node *insert(int inorder[],int preorder[],int top,int bottom) 
{
	int k;
	struct node *ptr;
	if(top>bottom)
	{
		return NULL;
	}
	ptr=(struct node *)malloc(sizeof(struct node));
	ptr->data=preorder[key];
	ptr->lchild=NULL;
	ptr->rchild=NULL;
	key++;
	if(top==bottom)
	{
		return ptr;
	}
	for(k=top;k<=bottom;k++)
	{
		if(inorder[k]==ptr->data)
		{
			break;
		}
	}
	ptr->lchild=insert(inorder,preorder,top,k-1);
	ptr->rchild=insert(inorder,preorder,k+1,bottom);

	return ptr;
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
		int inorder[n+5];
		int preorder[n+5];
		for(i=0;i<n;i++)
		{
			scanf("%d",&preorder[i]);
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&inorder[i]);
		}
		struct node *root=insert(inorder,preorder,0,n-1);
		/*	postorder(root);
			printf("\n");*/
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



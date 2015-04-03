#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* lchild;
	struct node* rchild;
};
int level=0,l=0;
int arr[10000];
struct node *search(struct node *,int);
void binsert(int val, struct node *root)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node)),*base = root;
	temp->data = val;
	temp->lchild = NULL;
	temp->rchild = NULL;
	while(1)
	{
		if(base->data > val)
		{
			if(base->lchild == NULL)
			{
				base->lchild = temp;
				break;
			}
			base = base->lchild;
		}
		else
		{
			if(base->rchild == NULL)
			{
				base->rchild  = temp;
				break;
			}
			base = base->rchild;
		}
	}
} 
int findlevel(struct node* root,int ptr,int level)
{
	if(root->data == ptr)
		return level;

	if(root->lchild == NULL && root->rchild == NULL)
		return ;

	int levelleft =  findlevel(root->lchild, ptr, level+1);
	int levelright = findlevel(root->rchild, ptr, level+1);

	if(levelleft == -1)
		return levelright;
	else
		return levelleft;
}
void transverse_Level(struct node* root, int level)
{
	if(root == NULL)
		return;
	if(level == 0)
	{
		arr[l]=root->data;
		l++;
	}
		

	else if (level > 0)
	{
		transverse_Level(root->lchild, level-1);
		transverse_Level(root->rchild, level-1);
	}
}
struct node *search(struct node *root,int value)
{
	while(root!=NULL)
	{
		if(value < root->data)
		{
                         root=root->lchild;
		}
		else if(value > root->data)
			root=root->rchild;
		else
		{
			printf("%d ",root->data);
			return root;
		}
	}
	return NULL;
}
void inorder(struct node *root)
{
	if(root==NULL)
	{
	     return ;
	}
	inorder(root->lchild);
	arr[l]=root->data;
	l++;
	inorder(root->rchild);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	level=0;
	l=0;
	struct node *root;
	int n,i,flag=0,p,q,main;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		arr[i]=-1;
	}
	root = (struct node*)malloc(sizeof(struct node));
	root->lchild = NULL;
	root->rchild = NULL;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(i == 0)
		{
			root->data = a[0];
			continue;
		}
		binsert(a[i],root);
	}
	scanf("%d %d",&p,&q);
	int out=findlevel(root,p,level);
	printf("%d ",out);
        transverse_Level(root,out);
	for(i=0;i<l;i++)
	{
		if(arr[i]==p)
		{
			if(arr[i+1]==-1)
			{
				main=arr[i+1];
				printf("$ $\n");
				flag=1;
				break;
			}
			else
			{
				main=arr[i+1];
				printf("%d ",arr[i+1]);
				flag=1;
				break;
			}
		}
		if(flag==1)
			break;
	}
	if(main!=-1)
	{
		l=0;
		struct node *temp;
		temp=search(root,main);
                inorder(temp);
		if(l<q)
		{
			printf("$\n");
		}
		else
		printf("%d\n",arr[q-1]);
	}
	}
	
	return 0;
}

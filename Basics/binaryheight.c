#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* lchild;
	struct node* rchild;
};
int maxheight(struct node* node)
{
	if (node==NULL)
		return 0;
	else
	{
		int lheight = maxheight(node->lchild);
		int rheight = maxheight(node->rchild);

		if (lheight > rheight)
			return(lheight+1);
		else 
			return(rheight+1);
	}
}
int num_leafnodes(struct node *node)
{
	if (node==NULL)
		return 0;
	else if(node->lchild==NULL && node->rchild==NULL)
		return 1;
	else
	{
		int a=num_leafnodes(node->lchild);
		int b=num_leafnodes(node->rchild);
		return a+b;
	}
}    
void transverse_Level(struct node* root, int level)
{
	if(root == NULL)
		return;
	if(level == 1)
		printf("%d ", root->data);

	else if (level > 1)
	{
		transverse_Level(root->lchild, level-1);
		transverse_Level(root->rchild, level-1);
	}
}
void print_order(struct node* root)
{
	int h = maxheight(root);
	int i;
	for(i=1; i<=h; i++)
		transverse_Level(root, i);
}

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
int main()
{
	struct node *root;
	int n,i,elem,f=0;
	scanf("%d",&n);
	int a[n];
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
	printf("Height of tree is: %d\n",maxheight(root));
	int num=num_leafnodes(root);
	printf("No of leaf nodes: %d\n",num);
	printf("No of non-leaf nodes: %d\n",n-num);
	print_order(root);
	printf("\n");
	return 0;
}

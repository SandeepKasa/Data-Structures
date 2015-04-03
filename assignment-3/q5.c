#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* lchild;
	struct node* rchild;
};

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

struct node * searchparent(struct node *root, int temp)
{
    if(root->lchild != NULL && root->lchild->data == temp)
    {
        return root;
    }
    else if(root->lchild != NULL)
    {
        searchparent(root->lchild, temp);
        if(root->rchild != NULL)
            searchparent(root->rchild, temp);
    }
 
    if(root->rchild != NULL && root->rchild->data == temp)
    {
        return root;
    }
    else if(root->lchild != NULL)
    {
        searchparent(root->lchild, temp);
        if(root->rchild != NULL)
            searchparent(root->rchild, temp);
    }
}

int main()
{
        int t;
        scanf("%d",&t);
        while(t--)
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
	int p;
	scanf("%d",&p);
	struct node *par;
	par=searchparent(root,p);
	int flag;
	flag=par->data;
//	printf("%d\n",par->rchild->data);
	printf("%d\n",flag);
        }
return 0;
}    

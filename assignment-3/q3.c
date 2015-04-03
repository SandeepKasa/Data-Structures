#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
struct node 
{
	int data; 
	int h;
	struct node *next[2];
};
struct node *root = NULL;
struct node * createnode(int );
int height(struct node *);
int maximum(int ,int );
struct node *right_rotate(struct node *);
struct node *left_rotate(struct node *);
struct node *insert(struct node *,int );
struct node *minimum(struct node *);
struct node  *delete(struct node *,int );
int getdiff(struct node *);
struct node * createnode(int data) 
{
	struct node *newnode;
	newnode = (struct node *)malloc(sizeof (struct node));
	newnode->data    = data;
	newnode->h = 1;
	newnode->next[0] = newnode->next[1] = NULL;
	return newnode;
}
int height(struct node *root)
{
	if (root == NULL)
		return 0;
	return root->h;
}
int maximum(int a, int b)
{
	return (a > b)? a : b;
}
struct node *right_rotate(struct node *root)
{
	struct node *temp1 = root->next[0];
	struct node *temp2 = temp1->next[1];
	temp1->next[1] =root;
	root->next[0] =temp2;
	root->h = maximum(height(root->next[0]), height(root->next[1]))+1;
	temp1->h = maximum(height(temp1->next[0]), height(temp1->next[1]))+1;
	return temp1;
}
struct node *left_rotate(struct node *root)
{
	struct node *temp1 = root->next[1];
	struct node *temp2 = temp1->next[0];
	temp1->next[0] = root;
	root->next[1] = temp2;
	root->h = maximum(height(root->next[0]), height(root->next[1]))+1;
	temp1->h = maximum(height(temp1->next[0]), height(temp1->next[1]))+1;
	return temp1;
}
int getdiff(struct node *root)
{
	if (root == NULL)
		return 0;
	return height(root->next[0]) - height(root->next[1]);
}
struct node* insert(struct node* root, int data)
{
	int diff;
	if (root == NULL)
		return(createnode(data));
	if (data < root->data)
		root->next[0]  = insert(root->next[0], data);
	else if(data > root->data)
		root->next[1] = insert(root->next[1], data);
	root->h = maximum(height(root->next[0]), height(root->next[1])) + 1;
	diff = getdiff(root);
	if (diff > 1 && data < root->next[0]->data)
		return right_rotate(root);
	if (diff < -1 && data > root->next[1]->data)
		return left_rotate(root);
	if (diff > 1 && data > root->next[0]->data)
	{
		root->next[0] =  left_rotate(root->next[0]);
		return right_rotate(root);
	}
	if (diff < -1 && data < root->next[1]->data)
	{
		root->next[1] = right_rotate(root->next[1]);
		return left_rotate(root);
	}
	return root;
}

struct node * minimum(struct node *root )
{
	struct node* temp = root;
	if(root==NULL)
		return root;
	while (temp->next[0] != NULL)
		temp=temp->next[0];
        return temp;
}
struct node* delete(struct node *root,int data)
{
	if (root == NULL)
		return root;
	if ( data > root->data )
		root->next[1] = delete(root->next[1],data);
	else if( data < root->data )
		root->next[0] = delete(root->next[0],data);
	else
	{
		if( (root->next[0]== NULL) || (root->next[1] == NULL) )
		{
			struct node *temp = root->next[0] ? root->next[0] : root->next[1];
			if(temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else 
				*root = *temp;
                        free(temp);
	         }
		else
		{
			struct node* temp = minimum(root->next[1]);
			root->data = temp->data;
			root->next[1] = delete(root->next[1], temp->data);
		}
	}
	if (root == NULL)
		return root;
	root->h = maximum(height(root->next[0]), height(root->next[1])) + 1;
	int diff = getdiff(root);
	if (diff > 1 && getdiff(root->next[0]) >= 0)
		return right_rotate(root);
	if (diff > 1 && getdiff(root->next[0]) < 0)
	{
		root->next[0] =  left_rotate(root->next[0]);
		return right_rotate(root);
	}
	if (diff < -1 && getdiff(root->next[1]) <= 0)
		return left_rotate(root);
	if (diff < -1 && getdiff(root->next[1]) > 0)
	{
		root->next[1] =right_rotate(root->next[1]);
		return left_rotate(root);
	}
         return root;
}
void preorder(struct node *root, struct node *R)
{
	if (root == NULL)
		return;
	if (root != R)
		printf(" %d", root->data);
	preorder(root->next[0], R);
	preorder(root->next[1], R);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	int q,n,i;
	char c;
	scanf("%d",&q);
	root=NULL;
	for(i=0;i<q;i++)
	{
		getchar();
		scanf("%c",&c);
		if(c=='i')
		{
			scanf("%d",&n);
			root=insert(root,n);
		}
	//	printf("%d",root->data);
		else if(c=='d')
		{
			scanf("%d",&n);
			root=delete(root,n);
		}
		else if(c=='p')
		{
//			flag=0;
			if (root != NULL)
				printf("%d", root->data);
			preorder(root, root);
			printf("\n");
		}
	}
	}
	return 0;
}

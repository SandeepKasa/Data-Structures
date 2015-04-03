#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int n;
	struct node * next;
}node;
void push(int x,node ** start)
{
	node * temp = (node *)malloc(sizeof(node));
	temp->n = x;
	temp->next = NULL;
	if(start[0]==NULL)
		start[0]=temp;
	else
	{
		temp->next = start[0];
		start[0] = temp;
	}
}
void pop(node ** start)
{
	if(start[0]==NULL)
		return;
	else
		start[0] = start[0]->next;
}
void print(node * head)
{
	while(head!=NULL)
	{
		printf("%d ",head->n);
		head = head->next;
	}
	printf("\n");
}
int main()
{
	int t,n;
	scanf("%d",&t);
	node * head = NULL;
	while(t--)
	{
		scanf("%d",&n);
		push(n,&head);
		print(head);
	}
	pop(&head);
	pop(&head);
	print(head);
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int n;
	struct node * next;
}node;
void enque(int x,node ** start)
{
	node * head = start[0];
	node * temp = (node *)malloc(sizeof(node));
	temp->n = x;
	temp->next = NULL;
	if(start[0]==NULL)
		start[0]=temp;
	else
	{
		while(start[0]!=NULL)
		{
			if(start[0]->next==NULL)
				break;
			start[0]=start[0]->next;
		}
		start[0]->next = temp;
		start[0]=head;
	}
}
void deque(node ** start)
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
		enque(n,&head);
		print(head);
	}
	deque(&head);
	deque(&head);
	print(head);
	return 0;
}

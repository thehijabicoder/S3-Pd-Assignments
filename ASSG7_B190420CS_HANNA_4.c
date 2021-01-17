include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

typedef struct queue
{
	node *head;
	node *tail;
}queue;

node* create_node(int k)
{
	node* temp;
	temp=(node*)malloc(sizeof(node));
	temp->data=k;
	temp->next=NULL;
	return temp;
}

int queueempty(queue *q)
{
	if(q->head==NULL)
	return -1;
	else return 1;
}

void enqueue(queue *q,node *x)
{
	if(queueempty(q)==-1)
    {
    	q->head=x;
    	q->tail=x;
    }
	else
	{
		q->tail->next=x;
		q->tail=q->tail->next;
	}
}

int dequeue(queue *q)
{
	if(queueempty(q)==-1)
	return -1;
	
	int x=q->head->data;
	node *p=q->head;
	if(q->head==q->tail)
	q->tail=NULL;
	
	q->head=q->head->next;
	free(p);
	return x;
} 

void main()
{  
    queue q;
    q.head=NULL;
    q.tail=NULL;
    int k;
	char ch;
	menu:
		scanf("%c",&ch);
		switch(ch)
		{
			case 'i': scanf("%d",&k);
			          enqueue(&q,create_node(k));
			          break;
			case 'd': printf("\n%d",dequeue(&q));
			          break;
			case 'e': printf("\n%d",queueempty(&q));
			          break;
			case 't': exit(0);
		}
	goto menu;
}

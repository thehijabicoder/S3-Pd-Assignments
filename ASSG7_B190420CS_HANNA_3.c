#include<stdio.h>
#include<stdlib.h>

typedef struct Queue
{
	int head;
	int tail;
	int n;
	int a[];
}queue;

int queuefull(queue *q)
{
	if(q->tail==q->head-1 || (q->tail==q->n && q->head==0))
	return -1;
	else return 1;
}

int queueempty(queue *q)
{
	if(q->head==-1 || q->head==q->tail)
	return -1;
	else return 1;
}

void enqueue(queue *q,int k)
{
	if(queuefull(q)==1)
	{
		if(q->head==-1)
		q->head++;
			
		q->a[q->tail]=k;
		
		if(q->tail==q->n)
		q->tail=0;
		else
		q->tail++;
	}
	else
	printf("\n%d",-1);
}

int dequeue(queue *q)
{
	if(queueempty(q)==-1)
	return -1;
	
	int x=q->a[q->head];
	
	if(q->head==q->n)
	q->head=0;
	else
	q->head++;
	
	return x; 
}

void main()
{
	queue q;
	q.head=-1;
	q.tail=0;
	int k;
	char ch;
	scanf("%d",&q.n);
	menu:
		scanf("%ch",&ch);
		switch(ch)
		{
			case 'i': scanf("%d",&k);
			          enqueue(&q,k);
			          break;
 			case 'd': printf("\n%d",dequeue(&q));
			          break;
 			case 'f': printf("\n%d",queuefull(&q));
			          break;
			case 'e': printf("\n%d",queueempty(&q));
			          break;
 			case 't': exit(0);
		}
	goto menu;
}

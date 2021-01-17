#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int key;
	struct node *next;
}node;

typedef struct linkedlist
{
	node *head;
}linkedlist;

node* create_node(int k)
{
	node* temp;
	temp=(node*)malloc(sizeof(node));
	temp->key=k;
	temp->next=NULL;
	return temp;
}

void list_insert_front(linkedlist *l, node* x)
{
	x->next=l->head;
	l->head=x;
}

void list_insert_tail(linkedlist *l, node* x)
{
	if(l->head==NULL)
	 l->head=x;
	else
	{
		node *p=l->head;
		while(p->next!=NULL)
		 p=p->next;
		p->next=x;
	}
}

void list_insert_after(linkedlist* l, node* x, node* y)
{   
   x->next=y->next;
   y->next=x;
}

void list_insert_before(linkedlist* l,node* x,node* y)
{
   node *p=l->head;
   while(p->next!=y)
    p=p->next;
   p->next=x;
   x->next=y;
}

int list_delete(linkedlist* l, node* x)
{   
    if(x==NULL)
     return -1;
    int d=x->key;
	node* p=l->head;
	while(p->next!=x)
     p=p->next;
    p->next=x->next;
	free(x);
	return d;	
}

int list_delete_first(linkedlist* l)
{  
   if(l->head==NULL)
    return -1;
   int d=l->head->key;
   node* x=l->head;
   l->head=l->head->next;
   free(x);
   return d;
}

int list_delete_last(linkedlist* l)
{
	if(l->head==NULL)
	 return -1;
	else
	{   int d;
		node *cursor=l->head, *pre=NULL;
		while(cursor->next!=NULL)
		{ 
		  pre=cursor;
		  cursor=cursor->next;	  
	   }
	   d=cursor->key;
	   if(pre!=NULL)
	    pre->next=NULL;
	   if(cursor==l->head)
	    l->head=NULL;
	   free(cursor);
	   return d;
    }
}

node* list_search(linkedlist* l, int k)
{
	if(l->head==NULL)
	 return NULL;
	else
	{
		node* p;
		p=l->head;
		while(p!=NULL&&p->key!=k)
		 p=p->next;
		return p;
		
	}
}

void main()
{   
    int k,n;
    node* x;
    linkedlist l;
    l.head=NULL;
	char ch;
	menu:
		scanf("%c",&ch);
		switch(ch)
		{
			case 'f': scanf("%d",&k);
			          x=create_node(k);
			          list_insert_front(&l,x);
				     break;
			case 't': scanf("%d",&k);
			          x=create_node(k);
			          list_insert_tail(&l,x);
			         break;
			case 'a': scanf("%d %d",&k,&n);
			          x=create_node(k);
			          list_insert_after(&l,x,list_search(&l,n));
			         break;
			case 'b': scanf("%d %d",&k,&n);
			          x=create_node(k);
			          list_insert_before(&l,x,list_search(&l,n));
			         break;
			case 'd': scanf("%d",&k);
			          n=list_delete(&l,list_search(&l,k));
			          printf("\n%d",n);
			         break;
			case 'i': n=list_delete_first(&l);
			          printf("\n%d",n);
			         break;
			case 'l': n=list_delete_last(&l);
			          printf("\n%d",n);
			         break;
			case 's': scanf("%d",&k);
			          x=(node*)malloc(sizeof(node));
			          x=list_search(&l,k);
			          if(x!=NULL)
			           printf("\n%d",1);
			         else
			           printf("\n%d",-1);
			         break;
			case 'e':exit(0);
			         break;
		}
		goto menu;
}

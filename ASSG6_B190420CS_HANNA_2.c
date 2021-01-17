#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int key;
	struct node *next;
	struct node *prev;
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
	temp->prev=NULL;
	return temp;
}

void list_insert_front(linkedlist *l, node* x)
{
	x->next=l->head;
	if(l->head!=NULL)
	 l->head->prev=x;
	l->head=x;
	x->prev=NULL;
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
		x->prev=p;
	}
}

void list_insert_after(linkedlist* l, node* x, node* y)
{   
   if(y!=NULL)
  {
   x->next=y->next;
   y->next=x;
  }
   x->prev=y;
   if(x->next!=NULL)
    x->next->prev=x;
}

void list_insert_before(linkedlist* l,node* x,node* y)
{ 
  if(y!=NULL)
  {
   if(y->prev!=NULL)
   {
    y->prev->next=x;
    x->prev=y->prev;
   }
   else
    {
	 x->prev=NULL;
	 l->head=x;
    }
   y->prev=x;
  }
   x->next=y;
   
}

int list_delete(linkedlist* l, node* x)
{   
    if(x==NULL)
     return -1;
    int d=x->key;
    if(x!=l->head)
    x->prev->next=x->next;
    if(x->next!=NULL)
    x->next->prev=x->prev;
    if(x==l->head)
    l->head=l->head->next;
	free(x);
	return d;	
}

int list_delete_initial(linkedlist* l)
{  
   if(l->head==NULL)
    return -1;
   int d=l->head->key;
   node* x=l->head;
   if(l->head->next!=NULL)
    l->head->next->prev=NULL;
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
		node *p=l->head;
		while(p->next!=NULL)
		{ 
		  p=p->next;	  
	    }
	   d=p->key;
	   if(p->prev!=NULL)
	    p->prev->next=NULL;
	   if(p==l->head)
	    l->head=NULL;
	   free(p);
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
			case 'i': n=list_delete_initial(&l);
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

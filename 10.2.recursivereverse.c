#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int key;
    struct node* next;
}node;

typedef struct linkedlist
{
    node* head;
}list;

node* create_node(int k)
{
	node* temp;
	temp=(node*)malloc(sizeof(node));
	temp->key=k;
	temp->next=NULL;
	return temp;
}

void list_insert_front(list *l, node* x)
{
	x->next=l->head;
	l->head=x;
}

void list_insert_tail(list *l, node* x)
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

void list_insert_after(list* l, node* x, node* y)
{   
   x->next=y->next;
   y->next=x;
}

void list_insert_before(list* l,node* x,node* y)
{
   node *p=l->head;
   while(p->next!=y)
    p=p->next;
   p->next=x;
   x->next=y;
}

int list_delete(list* l, node* x)
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

int list_delete_first(list* l)
{  
   if(l->head==NULL)
    return -1;
   int d=l->head->key;
   node* x=l->head;
   l->head=l->head->next;
   free(x);
   return d;
}

int list_delete_last(list* l)
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

node* list_search(list* l, int k)
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

node* reverse(node* head)
{
   if(head==NULL || head->next==NULL)
        return head;
    else
    {
        node* rest=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return rest;
    }
}

void display(list* l)
{
    node* cursor;
    cursor=l->head;
    while(cursor!=NULL)
    {
        printf(" %d",cursor->key);
		cursor=cursor->next;
    }
}

void main()
{   
    int k,n;
    node* x;
    list l;
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
            case 'h': display(&l);
					 break;
            case 'r': l.head=reverse(l.head); break;
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

#include<stdio.h>
#include<stdlib.h>

typedef struct PCB
{
	int id;
	char* state;
	struct PCB *next;
}node;

typedef struct PCBlist
{
	node *head;
}list;

node* create_node(int k)
{
	node* temp;
	temp=(node*)malloc(sizeof(node));
	temp->id=k;
	temp->next=NULL;
	return temp;
}

void list_insert_front(list *l, node* x)
{
	x->next=l->head;
	l->head=x;
}

int list_delete(list* l, node* x)
{   
    if(x==NULL)
     return -1;
    int d=x->id;
	node* p=l->head;
	while(p->next!=x)
     p=p->next;
    p->next=x->next;
	free(x);
	return d;	
}

char* get_state(int k, list* l)
{
	if(l->head==NULL)
	 return -1;
	else
	{
		node* p;
		p=l->head;
		while(p!=NULL&&p->id!=k)
		 p=p->next;
		return p->state;
		
	}
}

void list_waiting_processes(list* l)
{
	if(l->head==NULL)
	 printf("empty list")
	else
	{
		node* p;
		p=l->head;
		while(p!=NULL)
		{
		  if(strcmpi(p->state,'waiting')==0)
		   printf("%d",p->id);
		  p=p->next;
	    }
	}
}

void update_state(list* l,int k,char* s)
{
	    node* p;
		p=l->head;
		while(p!=NULL&&p->id!=k)
		 p=p->next;
		if(p->id==k)
		 strcpy(p->state,s);		
}

node* list_search(list* l, int k)
{
	if(l->head==NULL)
	 return NULL;
	else
	{
		node* p;
		p=l->head;
		while(p!=NULL&&p->id!=k)
		 p=p->next;
		return p;	
	}
}

void main()
{   
    int k,n;
    char string[15];
    node* x;
    list l;
    l.head=NULL;
	char ch;
	menu:
		scanf("%c",&ch);
		switch(ch)
		{
			case 'i': scanf("%d %s",&k,string);
			          x=create_node(k);
			          strcpy(x->state,string);
			          list_insert_front(&l,x);
				     break;
			case 'd': scanf("%d",&k);
			          x=create_node(k);
			          list_insert_tail(&l,x);
			         break;
			case 'g': scanf("%d %d",&k,&n);
			          x=create_node(k);
			          list_insert_after(&l,x,list_search(&l,n));
			         break;
			case 'l': scanf("%d %d",&k,&n);
			          x=create_node(k);
			          list_insert_before(&l,x,list_search(&l,n));
			         break;
			case 'u': scanf("%d",&k);
			          n=list_delete(&l,list_search(&l,k));
			          printf("\n%d",n);
			         break;
			case 'e': n=list_delete_first(&l);
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

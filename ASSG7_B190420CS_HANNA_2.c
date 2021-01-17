#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

typedef struct stack
{
	node *top;
}stack;

node* create_node(int k)
{
	node* temp;
	temp=(node*)malloc(sizeof(node));
	temp->data=k;
	temp->next=NULL;
	return temp;
}

void push(stack *s,node* x)
{
	x->next=s->top;
	s->top=x;
}

int pop(stack *s)
{
	if(stack_empty(s)==-1)
	return -1;
	
		int x=s->top->data;
		node* p=s->top;
		s->top=s->top->next;
		free(p);
		return x;
}

int stack_empty(stack *s)
{
	if(s->top==NULL)
	 return -1;
	 else return 1;
}

void main()
{  
    stack s;
    s.top=NULL;
    int k;
	char ch;
	menu:
		scanf("%c",&ch);
		switch(ch)
		{
			case 'i': scanf("%d",&k);
			          push(&s,create_node(k));
			          break;
			case 'd': printf("\n%d",pop(&s));
			          break;
			case 'e': printf("\n%d",stack_empty(&s));
			          break;
			case 't': exit(0);
		}
	goto menu;
}

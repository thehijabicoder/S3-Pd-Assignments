#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

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
		int x=s->top->data;
		node* p=s->top;
		s->top=s->top->next;
		free(p);
		return x;
}

int evaluatepostfix(char postfix[])
{
	int i,a,b,n;
	stack s; s.top=NULL;
	for(i=0;postfix[i]!='\0';i++)
	{
		if(postfix[i]==' ')
		continue;
		else if(isdigit(postfix[i]))
		{   
		    n=0;
			while(isdigit(postfix[i]))	
			 {
			    n=n*10+(int)(postfix[i]-'0');
			    i++;
		     }
		     i--;
		     push(&s,create_node(n));
		}
		else if(postfix[i]=='+')
		{   
			a=pop(&s);
			b=pop(&s);
			push(&s,create_node(b+a));
		}
		else if(postfix[i]=='-')
		{
			a=pop(&s);
			b=pop(&s);
			push(&s,create_node(b-a));
		}
		else if(postfix[i]=='*')
		{
			a=pop(&s);
			b=pop(&s);
			push(&s,create_node(b*a));
		}
		else if(postfix[i]=='/')
		{
			a=pop(&s);
			b=pop(&s);
			push(&s,create_node(b/a));
		}
	}
	return pop(&s);
}

void main()
{
	char expression[999999];
	scanf("%[^\n]%*c",expression);
	printf("%d",evaluatepostfix(expression));
}

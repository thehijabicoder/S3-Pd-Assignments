#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node
{
	char data;
	struct node *next;
}node;

typedef struct stack
{
	node *top;
}stack;

node* create_node(char k)
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

char pop(stack *s)
{
		int x=s->top->data;
		node* p=s->top;
		s->top=s->top->next;
		free(p);
		return x;
}

int outpriority(char x)
{
	switch(x)
	{
		case '+':return 1;
		case '-':return 1;
		case '*':return 2;
		case '/':return 2;
		case '(':return 3;
	}
}

int inpriority(char x)
{
	switch(x)
	{
		case '+':return 1; 
		case '-':return 1; 
		case '*':return 2; 
		case '/':return 2; 
		case '(':return 0; 
	}
}

char* infixtopostfix(char infix[])
{
	int i,j=0;
	stack op;
	op.top=NULL;
	char* postfix=(char*)malloc(strlen(infix)*sizeof(char));
	
	for(i=0;infix[i]!='\0';i++)
	{
		if(infix[i]>='a'&&infix[i]<='z')
		{
			postfix[j]=infix[i];
			j++;
		}
		else if(infix[i]==')')
		{
			while(op.top->data!='(')
			{
				postfix[j]=pop(&op);
				j++;
			}
			pop(&op);
		}
		else 
		{
			while(op.top!=NULL && inpriority(op.top->data)>=outpriority(infix[i]))
			{
				postfix[j]=pop(&op);
				j++;
			}
			push(&op,create_node(infix[i]));
		}
		
	}
	while(op.top!=NULL)
	{
		postfix[j]=pop(&op);
		j++;
	}
	postfix[j]='\0';
	return postfix;
}

void main()
{
	char expression[999999];
	scanf("%s",expression);
	printf("%s",infixtopostfix(expression));
	
}

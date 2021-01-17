#include<stdio.h>
#include<stdlib.h>

typedef struct Stack
{
	int top;
	int n;
	int a[];
}stack;

int stack_empty(stack* s)
{
	if (s->top==-1)
	 return -1;
	else return 1;
}

int stack_full(stack* s)
{
	if(s->top==s->n-1)
	return 1;
	else return 0;
}

void push(stack* s,int k)
{
	if(!stack_full(s))
	{
		s->a[s->top+1]=k;
		s->top=s->top+1;
	}
}

int pop(stack* s)
{
    if(stack_empty(s)==-1)
    return -1;
	
		int x=s->a[s->top];
		s->top=s->top-1;
		return x;
}

void main()
{
	stack s;
	int k;
	s.top=-1;
	scanf("%d",&s.n);
 	char ch;
 	menu:
 		scanf("%c",&ch);
 		switch(ch)
 		{
 			case 'i': scanf("%d",&k);
 			          push(&s,k);
			          break;
 			case 'd': printf("\n%d",pop(&s));
			          break;
 			case 'e': printf("\n%d",stack_empty(&s));
			          break;
 			case 't': exit(0);	
		}
	goto menu;
 }

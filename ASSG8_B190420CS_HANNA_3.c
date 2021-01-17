#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct node
{
	char data;
	struct node *left,*right;
	struct node *next;
}node;

typedef struct tree
{
	node *root;
	
}tree;

node* create_node(char k)
{
	node* temp;
	temp=(node*)malloc(sizeof(node));
	temp->data=k;
	return temp;
}
void push(tree *t,node* x)
{
	x->next=t->root;
	t->root=x;
}

node* pop(tree *t)
{
		node* p=t->root;
		t->root=t->root->next;
		return p;
}

node* construct_tree(char postfix[])
{
	tree t;
	t.root=NULL;
	int i;
	for(i=0;postfix[i]!='\0';i++)
	{
		if(isalpha(postfix[i]))
		{
			push(&t,create_node(postfix[i]));	
		}	
		else
		{
			node* n=create_node(postfix[i]);
			n->right=pop(&t);
			n->left=pop(&t);
			push(&t,n);
		}
	}	
	return t.root;
}

void inorder(tree *t)
{
	if(t->root==NULL)
	return;
	
	tree left;
	left.root=t->root->left;
	inorder(&left);
	
	printf("%c",t->root->data);
	
	
	tree right;
	right.root=t->root->right;
	inorder(&right);
}

void preorder(tree *t)
{
	if(t->root==NULL)
	return;
	
	printf("%c",t->root->data);
	
	tree left;
	left.root=t->root->left;
	preorder(&left);
	
	tree right;
	right.root=t->root->right;
	preorder(&right);
}

void postorder(tree *t)
{
	if(t->root==NULL)
	return;
	
	tree left;
	left.root=t->root->left;
	postorder(&left);
	
	tree right;
	right.root=t->root->right;
	postorder(&right);
	
	printf("%c",t->root->data);
}

void main()
{
	tree t;
	t.root=NULL;
	char expression[999999];
	char ch;
	menu:
		scanf("%c",&ch);
		switch(ch)
		{
			case 'e':scanf("%s",expression);
					 t.root=(node*)malloc(sizeof(node));
		    	     t.root=construct_tree(expression);
		        	 break;
			case 'i':printf("\n");
					 inorder(&t);
		   		     break;
			case 'p':printf("\n");
					 preorder(&t);
		    	     break;
			case 's':printf("\n");
					 postorder(&t);
					 break;
			case 't':exit(0);
		}
	goto menu;	
}


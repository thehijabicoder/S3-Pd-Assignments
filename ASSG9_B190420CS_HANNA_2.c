#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
	int mnbr;
	int price;
	char name[999999];
	struct node *left,*right,*p;
}node;

typedef struct tree
{
	node* root;
}tree;

node* create_node(int n,char s[],int p)
{
	node* temp=(node*)malloc(sizeof(node));
	temp->mnbr=n;
	strcpy(temp->name,s);
	temp->price=p;
	temp->p=NULL;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

void insert(tree* t,node* x)
{	
	node* y=NULL;
	node* z=t->root;
	while(z!=NULL)
	{
		y=z;
		if(x->mnbr<z->mnbr)
		z=z->left;
		else
		z=z->right;
	}
	x->p=y;
	if(y==NULL)
	t->root=x;
	else if(x->mnbr<y->mnbr)
	y->left=x;
	else
	y->right=x;
}

void transplant(tree* t,node* u,node* v)
{
	if(u->p==NULL)
	t->root=v;
	else if(u==u->p->left)
	u->p->left=v;
	else
	u->p->right=v;
	if(v!=NULL)
	v->p=u->p;
}

node* tree_minimum(node* x)
{
	while(x->left!=NULL)
	x=x->left;
	return x;
}

void delete(tree* t,node* x)
{
	if(x==NULL)
	{
		printf("%d\n",-1);
		return;
	}
	printf("%d %s %d\n",x->mnbr,x->name,x->price);
	if(x->left==NULL)
	transplant(t,x,x->right);
	else if(x->right==NULL)
	transplant(t,x,x->left);
	else
	{
		node* y=tree_minimum(x->right);
		if(y->p!=NULL)
		{
			transplant(t,y,y->right);
			y->right=x->right;
			y->right->p=y;
		}
		transplant(t,x,y);
		y->left=x->left;
		y->left->p=y;
	}
}

node* search(tree* t,int k)
{
	node* x=t->root;
	while(x!=NULL && k!=x->mnbr)
	{
		if(k<x->mnbr)
		x=x->left;
		else
		x=x->right;
	}
	return x;
}

void inorder(tree *t)
{
	if(t->root==NULL)
	return;
	
	tree left;
	left.root=t->root->left;
	inorder(&left);
	
	printf("%d %s %d\n",t->root->mnbr,t->root->name,t->root->price);
	
	
	tree right;
	right.root=t->root->right;
	inorder(&right);
}

void modify(tree* t,int n,int p)
{
	node* x=search(t,n);
	x->price=p;
}


void main()
{
	tree t;
	t.root=NULL;
	node* x=NULL;
	int n;
	int p;
	char s[999999];
	char ch;
	menu:
		scanf("%c",&ch);
		switch(ch)
		{
			case 'a':scanf("%d %s %d",&n,s,&p);
					 insert(&t,create_node(n,s,p));
					 break;
			case 'd':scanf("%d",&n);
					 delete(&t,search(&t,n));
					 break;
			case 's':scanf("%d",&n);
					 x=search(&t,n);
					 if(x!=NULL)
					 printf("%d %s %d\n",x->mnbr,x->name,x->price);
					 else
					 printf("%d\n",-1);
					 break;
			case 'i':inorder(&t);
					 break;
			case 'm':scanf("%d %d",&n,&p);
					 modify(&t,n,p);
					 break;
			case 'e':exit(0);
		}
	goto menu;
}

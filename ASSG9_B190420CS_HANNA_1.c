#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int key;
	struct node *left,*right,*p;
}node;

typedef struct tree
{
	node* root;
}tree;

node* create_node(int k)
{
	node* temp=(node*)malloc(sizeof(node));
	temp->key=k;
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
		if(x->key<z->key)
		z=z->left;
		else
		z=z->right;
	}
	if(x!=NULL)
	x->p=y;
	if(y==NULL)
	t->root=x;
	else if(x->key<y->key)
	y->left=x;
	else
	y->right=x;
}

void transplant(tree* t,node* u,node* v)
{
	if(u!=NULL)
	{
		if(u->p==NULL)
		t->root=v;
		else if(u->p->left!=NULL && u==u->p->left)
		u->p->left=v;
		else
		u->p->right=v;
		if(v!=NULL)
		v->p=u->p;
	}
}

node* tree_minimum(node* x)
{
	while(x->left!=NULL)
	x=x->left;
	return x;
}

void delete_(tree* t,node* x)
{
	if(x==NULL)
	{
		printf("\n%d",-1);
		return;
	}
	int d=x->key;
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
			if(y->right!=NULL)
			y->right->p=y;
		}
		transplant(t,x,y);
		y->left=x->left;
		if(y->keft!=NULL)
		y->left->p=y;
	}
	printf("\n%d",d);
}

node* search(tree* t,int k)
{
	node* x=t->root;
	while(x!=NULL && k!=x->key)
	{
		if(k<x->key)
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
	
	printf("%d ",t->root->key);
	
	
	tree right;
	right.root=t->root->right;
	inorder(&right);
}

void preorder(tree *t)
{
	if(t->root==NULL)
	return;
	
	printf("%d ",t->root->key);
	
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
	
	printf("%d ",t->root->key);
}


int main()
{
	tree t;
	t.root=NULL;
	node* x=NULL;
	int k;
	char ch;
	menu:
		scanf("%c",&ch);
		switch(ch)
		{
			case 'a':scanf("%d",&k);
					 insert(&t,create_node(k));
					 break;
			case 'd':scanf("%d",&k);
					 delete_(&t,search(&t,k));
					 break;
			case 's':scanf("%d",&k);
					 x=search(&t,k);
					 if(x!=NULL)
					 printf("\n%d",1);
					 else
					 printf("\n%d",-1);
					 break;
			case 'i':printf("\n");
					 inorder(&t);
					 break;
			case 'p':printf("\n");
					 preorder(&t);
					 break;
			case 't':printf("\n");
					 postorder(&t);
					 break;
			case 'e':exit(0);
		}
	goto menu;
	return 0;
}

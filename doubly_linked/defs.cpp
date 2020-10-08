#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>

typedef struct Node {
	int info;
	struct Node *left, *right;
}List_node, *Ptr;

void del(Ptr p, int* info) 
{
	Ptr q, r;
	*info = p->info;
	q = p->left, r = p->right;
	q->right = r, r->left = q;
	free(p);
}

void insert_after(Ptr p, int x)
{
	Ptr r, q;
	q = (List_node*)malloc(sizeof(List_node));
	q->info = x;
	r = p->left, r->left = q;
	q->right = r, q->left = p;
	p->right = q;
}
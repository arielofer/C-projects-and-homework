#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
	int info;
	struct Node* left, * right;
}List_node, * Ptr;

void del(Ptr *p, int* info)
{
	Ptr q, r;
	*info = (*p)->info;
	q = (*p)->left, r = (*p)->right;
	q->right = r, r->left = q;
	free(p);
}

//tar1
void insert_after(Ptr *p, int x)
{
	Ptr r, q;
	q = (List_node*)malloc(sizeof(List_node));
	q->info = x;
	r = (*p)->left, r->left = q;
	q->right = r, q->left = *p;
	(*p)->right = q;
}

//tar2
void insert_before(Ptr *p, int x)
{
	Ptr r, q;
	q = (List_node*)malloc(sizeof(List_node));
	q->info = x;
	r = (*p)->left, r->left = q;
	q->left = r, q->right = *p;
	(*p)->left = q;
}

//tar3
void del_after(Ptr *p, int* info)
{
	Ptr q, r;
	*info = (*p)->info;
	q = (*p)->right, r = q->right;
	(*p)->right = r, r->left = *p;
	free(q);
}

//tar4
void del_before(Ptr *head, Ptr p, int* info)
{
	Ptr q, r;
	*info = p->info;
	if (p->left == *head)
	{
		q = *head, r = q->left;
		r->right = p, p->left = r;
		if (r)
			*head = r;
		else
			*head = p;
	}
	else
	{
		q = p->left, r = q->left;
		r->right = p, p->left = r;
	}
	free(q);
}

//tar5
void del_by_value(Ptr *p, int x) 
{
	Ptr q, r;
	if ((*p)->info = x)
		del(p, &x);
	else
	{
		q = *p;
		while (q->right->info != x && q->right)
			q = q->right;
		if (q->right)
			del_after(&q, &x);
		else
		{
			r = *p;
			while (r->left->info != x && r->left)
				r = r->left;
			if (r->left)
				del_before(&r, &x);
			else
				printf("Error - couldnt find value");
		}
	}
}

//tar6
void insert_to_middle(Ptr *p1, Ptr *p2) 
{
	Ptr q = *p1, r = (*p1)->right;
	
	//find middle
	while (r)
	{
		r = r->right;
		q = q->right;
		if (!r)
			break;
		r = r->right;
	}

	//attach second list after q(middle)
	r = q->right;
	q->right = *p2;
	(*p2)->left = q;
	while (q->right)
		q = q->right;
	q->right = r;
	r->left = q;
}

//tar7
int poly(Ptr p)
{
	Ptr q = p->right;
	while (q->right)
		q = q->right;
	while (q != p)
	{
		if(q->info != p->info)

	}
}
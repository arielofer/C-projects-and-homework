#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
	int info;
	struct Node* left, * right;
}List_node, * Ptr;

void del(Ptr *head, Ptr p, int* info)
{
	Ptr q = NULL, r = NULL;
	*info = (p)->info;

	if ((p)->left)q = (p)->left;
	if ((p)->right) r = (p)->right;
	if (*head == p)
	{
		if (q)*head = q;
		else *head = r;
	}
	if (q)q->right = r;
	if (r)r->left = q;

	free(p);
}

//tar1
void insert_after(Ptr* p, int x)
{
	Ptr r, q;
	q = (List_node*)malloc(sizeof(List_node));
	q->info = x;
	if ((*p)->right)
	{
		r = (*p)->right, r->left = q;
		q->right = r, q->left = *p;
		(*p)->right = q;
	}
	else
	{
		(*p)->right = q;
		q->left = *p;
		q->right = NULL;
	}
}

//tar2
void insert_before(Ptr* p, int x)
{
	Ptr r, q;
	q = (List_node*)malloc(sizeof(List_node));
	q->info = x;
	if ((*p)->left)
	{
		r = (*p)->left, r->right = q;
		q->left = r, q->right = *p;
		(*p)->left = q;
	}
	else
	{
		(*p)->left = q;
		q->right = *p;
		q->left = NULL;
	}
}

//tar3
void del_after(Ptr *p, int* info)
{
	Ptr q, r;
	if ((*p)->right)
	{
		q = (*p)->right, r = q->right;
		*info = q->info;
		(*p)->right = r, r->left = *p;
		free(q);
	}
}

//tar4
void del_before(Ptr *head, Ptr p, int* info)
{
	Ptr q = NULL, r = NULL;
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
		q = p->left;
		if(q)r = q->left;
		if(r)r->right = p;
		p->left = r;
	}
	free(q);
}

//tar5
void del_by_value(Ptr *head, int x) 
{
	Ptr q, r, p;
	if ((*head)->info == x)
	{
		p = *head;
		del(head, p, &x);
	}
	else
	{
		q = *head;
		while (q->right && q->right->info != x)
			q = q->right;
		if (q->right)
			del_after(&q, &x);
		else
		{
			r = *head;
			while (r->left && r->left->info != x)
				r = r->left;
			if (r->left)
				del_before(head, r, &x);
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
		if (!r)
			break;
		q = q->right;
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
	while (q != p && p->left != q)
	{
		if (q->info != p->info)
			return 0;
		p = p->right;
		q = q->left;
	}

	return 1;
}

//tar8
void reverse(Ptr* p)
{
	int temp;
	Ptr q = (*p)->right, r = (*p);
	while (q->right)
		q = q->right;

	while (q != r && r->left != q)
	{
		//swap
		temp = q->info;
		q->info = r->info;
		r->info = temp;

		q = q->left;
		r = r->right;
	}
}

void print_list(Ptr p)
{
	while (p)
	{
		printf("%d==>", p->info); p = p->right;
	}
	printf("\n");
}

int main()
{
	int i;
	Ptr p = (Ptr)malloc(sizeof(List_node)), q;
	p->info = 1, p->left = p->right = NULL;
	for (i = 5; i > 1; i--)
		insert_after(&p, i);
	print_list(p);

	reverse(&p);
	print_list(p);

	return 0;
}
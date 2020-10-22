#include "queue.h"
#include <stdio.h>
#include <stdlib.h>


/*tar1*/
void PrePrint(tree_ptr T)
{
	printf("%d, ", T->data);
	if (T->left) PrePrint(T->left);
	if (T->right) PrePrint(T->right);
}

void InPrint(tree_ptr T)
{
	if (T->left) InPrint(T->left);
	printf("%d, ", T->data);
	if (T->right) InPrint(T->right);
}

void PostPrint(tree_ptr T)
{
	if (T->left) PostPrint(T->left);
	if (T->right) PostPrint(T->right);
	printf("%d, ", T->data);
}

void LevPrint(tree_ptr T)
{
	queue q;
	if (T)
	{
		queue_init(&q);
		enqueue(&q, T);
		while (!queue_empty(q))
		{
			T = dequeue(&q);
			printf("%d", T->data);
			if (T->left) enqueue(&q, T->left);
			if (T->right) enqueue(&q, T->right);
		}
	}
}

int IsInTree(tree_ptr T, ItemType x)
{
	if (!T->left && !T->right)
		return T->data == x;
	else
	{
		if (T->data < x && T->left) return IsInTree(T->left, x);
		else if (T->data > x && T->right) return IsInTree(T->right, x);
		else return 0;
	}
}

void Insert(tree_ptr* T, ItemType x)
{
	if (*T == NULL)
	{
		tree_ptr node = (tree_ptr)malloc(sizeof(tree_node));
		node->data = x;
		node->left = node->right = NULL;
		*T = node;
	}
	else
	{
		if (IsInTree(*T, x)) return;
		if ((*T)->data > x) return Insert(&((*T)->left), x);
		else if ((*T)->data < x) return Insert(&((*T)->right), x);
	}
}

tree_ptr following(tree_ptr T, ItemType x)
{
	/*if (T == NULL) return NULL;
	if (T->data == x) return following(T->right, x);
	else
	{
		if (T->left)
		{
			if (T->left->data == x)
			{
				if (T->left->right == NULL) return T;
				else return following(T->left->right, x);;
			}
		}
		else return following(T->left, x);
	}*/
	tree_ptr Tleft, Tright;
	if (T == NULL) return NULL;
	if (IsInTree(T->left, x))
	{
		Tleft = following(T->left, x);
		if (T->left == Tleft) return T;
		else
	}
	else
}

int main()
{
	tree_ptr T = NULL, fol;
	/*build tree*/
	Insert(&T, 5);
	Insert(&T, 6);
	Insert(&T, 3);
	Insert(&T, 4);
	Insert(&T, 1);
	Insert(&T, 2);

	/*prints*/
	PrePrint(T);
	printf("\n");
	InPrint(T);
	printf("\n");
	PostPrint(T);
	printf("\n");
	LevPrint(T);
	printf("\n");

	/*following*/
	fol = following(T, 3);
	printf("%d", fol->data);

	return 0;
}
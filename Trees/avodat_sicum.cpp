#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

int leaf(tree_ptr p)
{
	return (p->left == NULL && p->right == NULL);
}

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
		if (T->data == x) return 1;
		if (T->data > x && T->left) return IsInTree(T->left, x);
		else if (T->data < x && T->right) return IsInTree(T->right, x);
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

tree_ptr most_left(tree_ptr T)
{
	if (!T->left) return T;
	return most_left(T->left);
}

tree_ptr following(tree_ptr T, ItemType x)
{
	if (T == NULL) return NULL; //not found
	if (T->data == x)
	{
		if (T->right) return most_left(T->right);
	}
	else if(T->left)
	{
		if (T->left->data == x && T->left->right)
		{
			if (!leaf(T->left)) return following(T->left, x);
			else return T;
		}
		if (T->left->right && T->left->right->data == x)
		{
			if (!leaf(T->left->right)) return following(T->left, x);
			else return T;
		}
		if(leaf(T->left)) return T;
	}
	
	tree_ptr temp = following(T->left, x);
	if (temp) return temp;
	else return following(T->right, x);
}

void delete_node(tree_ptr* T, ItemType x)
{
	tree_ptr fol = NULL, temp;
	if (*T == NULL || !IsInTree(*T, x)) printf("value not found!");
	else
	{
		if ((*T)->data == x)
		{
			if (leaf(*T))
			{
				free(*T);
				*T = NULL;
			}
			else
			{
				fol = following(*T, x);
				if ( fol && (*T)->right == fol)
				{
					fol->left = (*T)->left;
					free(*T);
					*T = fol;
				}
				else
				{
					(*T)->data = (*T)->left->data;
					delete_node(&((*T)->left), (*T)->left->data);
					/*temp = following(*T, fol->data);
					temp->left = NULL;
					(*T)->data = fol->data;
					free(fol);*/
				}
			}
		}
		else
		{
			if (x < (*T)->data) delete_node(&((*T)->left), x);
			else delete_node(&((*T)->right), x);
		}
	}
}

/*tar2*/
int height(tree_ptr T)
{
	int Hleft, Hright;
	if (T == NULL) return 0;
	else
	{
		Hleft = height(T->left) + 1;
		Hright = height(T->right) + 1;
		return Hleft > Hright ? Hleft : Hright;
	}
}

void load_level(tree_ptr T, queue* q, int lev, int h)
{
	if (T != NULL)
	{
		if (h == lev) enqueue(q, T);
		else
		{
			load_level(T->left, q, lev + 1, h);
			load_level(T->right, q, lev + 1, h);
		}
	}
}

//seif bet - max in level
void max_in_lev(tree_ptr T)
{
	queue q; que_item max, temp;
	int h = height(T);
	if (T == NULL) return;
	for (int i = 0; i < h; i++)
	{
		queue_init(&q);
		load_level(T, &q, 0, i);
		max = dequeue(&q);
		while (!queue_empty(q))
		{
			temp = dequeue(&q);
			max = max->data < temp->data ? temp : max;
		}
		printf("in level %d max is %d\n", i, max->data);
	}
}

tree_ptr tree_builder() //for all the questions following
						//and including 2
{
	tree_ptr T = NULL;
	ItemType info;
	printf("enter numbers to insert to tree, stop with 0: ");
	scanf("%d", &info);
	while (info != 0)
	{
		Insert(&T, info);
		scanf("%d", &info);
	}

	//level scan (A)
	LevPrint(T); printf("\n");

	//print max in level (B)
	max_in_lev(T);

	return T;
}

/*tar3*/
int NodeCount(tree_ptr T)
{
	int left, right;
	if (T == NULL) return 0;
	if (leaf(T)) return 1;
	else
	{
		left = NodeCount(T->left);
		right = NodeCount(T->right);
		return left + right;
	}
}

int LeftBiggerThenRight(tree_ptr T)
{
	int left, right;
	if (leaf(T)) return 1;
	else
	{
		left = NodeCount(T->left);
		right = NodeCount(T->right);
		if (right > left) return 0;
		else return LeftBiggerThenRight(T->left);
	}
}

/*tar4*/
void max_level(tree_ptr T, int arr[], int level)
{
	if (T == NULL) return;
	arr[level]++;
	max_level(T->left, arr, level + 1);
	max_level(T->right, arr, level + 1);
}

void wrap_max_level(tree_ptr T)
{
	int arr[4] = { 0 }, i, max = 0;
	max_level(T, arr, 0);
	for (i = 1; i < 4; i++)
		max = arr[max] < arr[i] ? i : max;
	printf("level with max nodes is %d\n", max);
}

/*tar5*/
void print_fathers_in_level(tree_ptr T, int level, int curr)
{//curr is 0 at first call
	if (T == NULL || curr > level) return;
	if (curr < level)
	{
		print_fathers_in_level(T->left, level, curr + 1);
		print_fathers_in_level(T->right, level, curr + 1);
	}
	if (curr == level)
		if (!leaf(T)) printf("%d, ",T->data);
}

/*tar6*/
tree_ptr ReturnNode(tree_ptr T, ItemType x)
{
	if (!T->left && !T->right)
		return T->data == x? T:NULL;
	else
	{
		if (T->data == x) return T;
		if (T->data > x && T->left) return ReturnNode(T->left, x);
		else if (T->data < x && T->right) return ReturnNode(T->right, x);
		else return NULL;
	}
}

int avl_tree(tree_ptr T)
{
	if (T == NULL) return 1;
	else
	{
		if (height(T->left) - height(T->right) > 1 || height(T->left) -
			height(T->right) < -1) return 0;
		else return (avl_tree(T->left) && avl_tree(T->right));
	}
}

tree_ptr parent(tree_ptr T, tree_ptr child)
{
	if (T == NULL || child == NULL) return NULL;
	else
	{
		if (T->left == child || T->right == child) return T;
		else return (T->data < child->data) ? parent(T->right, child) : parent(T->left, child);
	}
}

tree_ptr find_wrong_tree(tree_ptr T, tree_ptr T2)
{
	if (T == T2)
		return T;
	else
	{
		if (height(T2->left) - height(T2->right) > 1 || height(T2->left) -
			height(T2->right) < -1) return T2;
		else return find_wrong_tree(T, parent(T, T2));
	}
}

int roll_check(tree_ptr T)
{
	tree_ptr Temp1 = T->left;
	tree_ptr Temp2 = T->right;
	if (T == NULL) return 0;//no problem
	else
	{
		if (Temp1)
		{
			if ((height(Temp1->left) - height(Temp1->right) == 1)&&
				height(Temp1) - height(Temp2) == 2)
				return 1;//LL_rotate

			if ((height(Temp1->left) - height(Temp1->right) == -1)&&
				height(Temp1) - height(Temp2) == 2)
				return 2;//LR_rotate
		}
		if (Temp2)
		{
			if ((height(Temp2->left) - height(Temp2->right) == 1)&&
				height(Temp1) - height(Temp2) == -2)
				return 3;//RL_rotate
			if ((height(Temp2->left) - height(Temp2->right) == -1)&&
				height(Temp1) - height(Temp2) == -2)
				return 4;//RR_rotate
		}
	}
}

void LL_rotate(tree_ptr* T, tree_ptr wrong)
{
	tree_ptr p = parent(*T, wrong), a = wrong->left;
	if (p)
	{
		if (p->left == wrong) p->left = a;
		else p->right = a;
	}
	else *T = a;

	wrong->left = a->right;
	a->right = wrong;
}

void LR_rotate(tree_ptr* T, tree_ptr wrong)
{
	tree_ptr p = parent(*T, wrong), a = wrong->left, b = NULL;
	if (a) b = a->right;
	if (p)
	{
		if (p->left == wrong) p->left = b;
		else p->right = b;
	}

	a->right = b->left;
	b->left = wrong->left;
	wrong->left = b->right;
	b->right = wrong;
	if (!p) *T = b;
}

void RL_rotate(tree_ptr* T, tree_ptr wrong)
{
	tree_ptr p = parent(*T, wrong), a = wrong->right, b = NULL;
	if (a) b = a->left;
	if (p)
	{
		if (p->left == wrong) p->left = b;
		else p->right = b;
	}

	a->left = b->right;
	b->right = wrong->right;
	wrong->right = b->left;
	b->left = wrong;
	if (!p) *T = b;
}
void RR_rotate(tree_ptr* T, tree_ptr wrong)
{
	tree_ptr p = parent(*T, wrong), a = wrong->right;
	if (p)
	{
		if (p->left == wrong) p->left = a;
		else p->right = a;
	}
	else *T = a;

	wrong->right = a->left;
	a->left = wrong;
}

tree_ptr build_avl()
{
	int status;
	tree_ptr T = NULL;
	ItemType x;
	printf("enter numbers to enter into tree, stop with 0:\n");
	scanf("%d", &x);
	while (x != 0)
	{
		Insert(&T, x);
		while (!avl_tree(T))
		{
			tree_ptr T1 = ReturnNode(T, x); //find node containing x 
			tree_ptr wrong = find_wrong_tree(T, T1);
			printf(" wrong =%d\n", wrong->data);
			status = roll_check(wrong);
			switch (status)
			{
			case 1:
				printf(" LL...masho =%d\n", roll_check(wrong));
				LL_rotate(&T, wrong);
				break;
			case 2:
				printf(" LR...masho =%d\n", (roll_check(wrong)));
				LR_rotate(&T, wrong);
				break;
			case 3:
				printf(" RL...masho =%d\n", (roll_check(wrong)));
				RL_rotate(&T, wrong);
				break;
			case 4:
				printf(" RR...masho =%d\n", (roll_check(wrong)));
				RR_rotate(&T, wrong);
				break;
			default:
				break;
			}
			InPrint(T);
			printf("\n");
		}
		scanf("%d", &x);
	}

	return T;
}

int main()
{
	tree_ptr T = NULL, fol, avl;
	
	//tar1
	/*build tree*/
	Insert(&T, 5);
	Insert(&T, 6);
	Insert(&T, 3);
	Insert(&T, 4);
	Insert(&T, 1);
	Insert(&T, 2);
	Insert(&T, 8);
	Insert(&T, 7);

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
	fol = following(T, 5);
	printf("%d\n", fol->data);

	/*delete node*/
	delete_node(&T, 8);
	InPrint(T); printf("\n\n");

	//tar2
	max_in_lev(T); printf("\n");

	//tar3
	printf("%d\n", LeftBiggerThenRight(T)); //false
	delete_node(&T, 7); delete_node(&T, 4); delete_node(&T, 2);
	printf("%d\n\n", LeftBiggerThenRight(T)); //true

	//tar4
	wrap_max_level(T); //1
	Insert(&T, 4);
	Insert(&T, 2);
	Insert(&T, 7);
	wrap_max_level(T); printf("\n"); //2

	//tar5
	print_fathers_in_level(T, 1, 0); //3, 6,
	printf("\n");
	print_fathers_in_level(T, 2, 0); //1,
	printf("\n");

	//tar6
	//avl trees
	avl = build_avl();

	return 0;
}
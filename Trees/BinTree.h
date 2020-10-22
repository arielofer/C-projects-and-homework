typedef int ItemType;

typedef struct Tnode
{
	ItemType data;
	struct Tnode* left;
	struct Tnode* right;
}tree_node, *tree_ptr;

/* Source Code From Laure Gonnord and Bernard Carré
 * Modified by Walter Rudametkin
 */

#include "trees.h"

//construction of a tree by return value
//struct node * cons(int val, struct node *left, struct node *right)
//{
//    PtNode new = malloc(sizeof(Node));
//    new->val=val;
//    new->left=left;
//    new->right=right;
//    return new;
//}

// construction of a tree by pointer
void cons_tree(struct node ** ptr_tree, int val, struct node *left, struct node *right)
{
	if ((*ptr_tree) == NULL)
		*ptr_tree = malloc(sizeof(Node));
	(*ptr_tree)->val = val;
	(*ptr_tree)->left = left;
	(*ptr_tree)->right = right;
}

// create an empty tree by return value
//struct node * mk_empty_tree()
//{
//	return NULL;
//}

// initialize un empty tree
void mk_empty_tree(struct node ** ptr_tree)
{
	*ptr_tree = NULL;
}

// tree is empty?
bool is_empty(struct node *tree)
{
	return tree==NULL;
}

// t is a leaf?
bool is_leaf(struct node *tree)
{
	return(!is_empty(tree) && is_empty(tree->left) && is_empty(tree->right));
}

// add x in a bst wtr its value.
void add(struct node **ptr_tree, int x)
{
	// printf("hey\n");
	Node *temp = NULL;
	if (!(*ptr_tree))	
	{
		// cons_tree(ptr_tree, x, NULL, NULL);
		temp = (Node *)malloc(sizeof(Node));
		temp->left = NULL;
		temp->right = NULL;
		temp->val = x;
		*ptr_tree = temp;
		return;
	}
	if ((*ptr_tree)->val <= x)
		add(&((*ptr_tree)->right), x);
	else
		add(&((*ptr_tree)->left), x);
}

// print values of tree in ascendant order (left-value-right)
void print_tree(struct node *tree)
{
	// printf("Hey\n");
	if (is_empty(tree))
		return;
	print_tree(tree->left);
	printf("%d ", tree->val);
	print_tree(tree->right);
}

// build a tree "add"ing values of the file fp
void load_tree(FILE *fp, struct node **ptr_tree)
{
	int val;
	while (fscanf(fp, "%d", &val) == 1)
	{
		add(ptr_tree, val);
	} 
}

// Free all memory used by the tree
void free_tree(struct node **ptr_tree)
{
	if ((*ptr_tree) == NULL)
		return;
	if ((*ptr_tree)->left == NULL && (*ptr_tree)->right == NULL)
		free(*ptr_tree);
		return;
	free_tree(&((*ptr_tree)->left));
	free_tree(&((*ptr_tree)->right));
}


// print pairs (father =L/R=> son)
void print_rec_edges(struct node *tree)
{
	if (tree->left != NULL)
		printf("%d->%d", tree->val, tree->left->val);
		print_rec_edges(tree->left);
	if (tree->right != NULL)
		printf("%d->%d", tree->val, tree->right->val);
		print_rec_edges(tree->right);
}

//PART II

// recursively prints arcs of the tree <value,left,right> into the file fp:
// "value -> left;"  if it exists
// "value -> right;" if it exists
// check for: !is_empty(t) & !is_leaf(t)
void recursive_dot(struct node *tree, FILE *fp)
{
	//TODO
}


// generate a .dot file for the tree
// limits (no arcs) :
//   is_empty(t) => "empty" digraph
//   is_leaf(t) => only one node
// general case :
//   calls recursive_dot which prints arcs
void generate_dot (struct node *t, FILE *fp)
{
	fprintf (fp, "digraph G {\n");
	if (!is_empty(t))
	{
		if (is_leaf(t))
		{
			fprintf(fp, "\t%d", t->val);
		}
		else
		{
			recursive_dot(t,fp);
		}
	}
	fprintf (fp, "}\n");
}

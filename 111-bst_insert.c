#include "binary_trees.h"
/**
 * bst_insert - inserts value in BST
 * @tree: pointer to root node
 * @value: value to store
 * Return: pointer to created node, NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *t = NULL;
	bst_t *s = NULL;
	bst_t *n = NULL;

	if (!tree)
		return (NULL);
	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));

	t = *tree;
	while (t)
	{
		s = t;
		if (value < t->n)
			t = t->right;
		else if (value > t->n)
			t = t->right;
		else if (value == t->n)
			return (NULL);

	}
	n = binary_tree_node(NULL, value);
	if (s == NULL)
		s = n;
	else if (value < s->n)
	{
		s->left = n;
		n->parent = s;

	}
	else
	{
		s->right = n;
		n->parent = s;
	}
	return (n);
}

#include "binary_trees.h"

/**
 * r_insert_node - main func
 * @tree: type
 * @parent: node of struct
 * @new: param 1
 * @nval: param 2
 * Return: pointer to root
 */
avl_t *r_insert_node(avl_t **tree, avl_t *parent, avl_t **new, int nval)
{
	int a;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, nval));
	if ((*tree)->n > nval)
	{
		(*tree)->left = r_insert_node(&(*tree)->left, *tree, new, nval);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < nval)
	{
		(*tree)->right = r_insert_node(&(*tree)->right, *tree, new, nval);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
	{
		return (*tree);
	}
	a = binary_tree_balance(*tree);
	if (a > 1 && (*tree)->left->n > nval)
	{
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (a > 1 && (*tree)->left->n < nval)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (a < -1 && (*tree)->right->n > nval)
	{
		*tree = binary_tree_rotate_left(*tree);
	}
	else if (a < -1 && (*tree)->right->n > nval)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	return (*tree);
}
/**
 * avl_insert - main function taht inserts value
 * @tree: pointer root
 * @value: value to store node
 * Return: inserted node, null on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	r_insert_node(tree, *tree, &new, value);
	return (new);
}

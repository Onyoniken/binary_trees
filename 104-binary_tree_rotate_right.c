#include "binary_trees.h"

/**
 * binary_tree_rotate_right - funct that rotates right
 * @tree: obj
 * Return: pointer to node
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *p;

	if (tree == NULL || tree->left == NULL)
	{
		return (NULL);
	}
	p = tree->left;
	tree->left = p->right;
	if (p->right != NULL)
	{
		p->right->parent = tree;
	}
	p->right = tree;
	p->parent = tree->parent;
	tree->parent = p;
	return (p);

}

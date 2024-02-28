#include "binary_trees.h"
/**
 * bst_search - looks for value in BST
 * @tree: pointer to root node
 * @value: value to search in tree
 * Return: pointer to node having value, NULL if tree is NUll, NULL no matches
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *node = (bst_t *)tree;

	if (!tree)
		return (NULL);

	while (node)
	{
		if (value == node->n)
			return (node);
		if (value < node->n)
			node = node->left;
		else if (value > node->n)
			node = node->right;
	}

	return (NULL);
}

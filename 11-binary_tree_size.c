#include "binary_trees.h"

/**
 * binary_tree_size - calculates size of binary tree
 * @tree: obj to calc size
 *
 * Return: tree size, 0 if NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

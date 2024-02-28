#include "binary_trees.h"

/**
 * binary_tree_height - measures height of binary tree
 * @tree: tree to get height of
 *
 * Return: tree height, 0 if null
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_a = 0;
	size_t height_b = 0;

	if (!tree)
		return (0);

	height_a = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_b = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_a > height_b ? height_a : height_b);
}

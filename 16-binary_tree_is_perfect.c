#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks binary tree perfect
 * @tree: pointer to root node
 *
 * Return: 1 if perfect, 0 if not perfect, if NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t a = 0;
	size_t b = 0;
	size_t c = 0;

	if (!tree)
		return (0);
	if (!tree->right && !tree->left)
		return (1);

	a = binary_tree_height(tree);
	b = binary_tree_size(tree);

	c = (size_t)_pow_recursion(2, a + 1);
	return (c - 1 == b);
}
/**
 * _pow_recursion - returns j raised k
 * @j: base
 * @k: power
 * Return: j raised k, -1 if negative
 */
int _pow_recursion(int j, int k)
{
	if (k < 0)
		return (-1);
	if (k == 0)
		return (1);
	else
		return (j * _pow_recursion(j, k - 1));
}
/**
 * binary_tree_size - measures binary tree size
 * @tree: to be measured
 * Return:  tree size, 0 if NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * binary_tree_height - tree height
 * @tree: tree height measurement
 * Return: tree height, 0 if NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t a = 0;
	size_t b = 0;

	if (!tree)
		return (0);
	a = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	b = tree->right ? 1 + binary_tree_height(tree->left) : 0;
	return (a > b ? a : b);
}


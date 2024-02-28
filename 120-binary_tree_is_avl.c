#include "binary_trees.h"

/**
 * binary_tree_is_avl - main function
 * @tree: pointer to root
 *
 * Return: 1 if avl, otherwise 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (btia_helper(tree, INT_MIN, INT_MAX));

}
/**
 * btia_helper - main function that finds binary tree
 * @tree: pointer to root node
 * @min: min value
 * @max: max value
 *
 * Return: 1 if tree otherwise 0
 */
int btia_helper(const binary_tree_t *tree, int min, int max)
{
	int a, b;

	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	a = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	b = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	if (abs(a - b) > 1)
		return (0);

	return (btia_helper(tree->left, min, tree->n - 1)
		&& btia_helper(tree->right, tree->n + 1, max));

}
/**
 * binary_tree_height - main function to measure tree height
 * @tree: obj
 *
 * Return: tree height, 0 if NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t a = 0;
	size_t b = 0;

	if (!tree)
		return (0);
	a = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	b = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (a > b ? a : b);
}

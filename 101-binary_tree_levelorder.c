#include "binary_trees.h"

/**
 * binary_tree_levelorder - traverses binary tree
 * @tree: object
 * @func: pointer to function
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t l, m;

	if (!tree || !func)
		return;
	m = binary_tree_height(tree) + 1;

	for (l = 1; l <= m; l++)
		btlo_helper(tree, func, l);
}
/**
 * btlo_helper - traverses binary tree through post order
 * @tree: obj
 * @func: pointer to function
 * @level: leevl to call function
 */
void btlo_helper(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (level == 1)
		func(tree->n);
	else
	{
		btlo_helper(tree->left, func, level - 1);
		btlo_helper(tree->right, func, level - 1);
	}
}
/**
 * binary_tree_height - calculates tree height
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

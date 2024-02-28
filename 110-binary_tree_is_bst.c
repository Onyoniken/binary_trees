#include "binary_trees.h"
/**
 * binary_tree_is_bst - main function checks a valid binary tree search
 * @tree: pointer to root node
 *
 * Return: 1 if tree is BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (btib_helper(tree, INT_MIN, INT_MAX));

}
/**
 * btib_helper - main function is a valid BST
 * @tree: pointer to root node
 * @min: min value
 * @max: max value
 *
 * Return: 1 if valid BST, 0 otherwise
 */
int btib_helper(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);
	return (btib_helper(tree->left, min, tree->n - 1)
		&& btib_helper(tree->right, tree->n + 1, max));
}

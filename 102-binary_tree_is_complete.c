#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if its complete
 * @tree: obj
 *
 * Return: 1 if complete, 0 if not/null
 *
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t s;

	if (!tree)
		return (0);
	s = binary_tree_size(tree);
	return (btic_helper(tree, 0, s));
}
/**
 * btic_helper - check whether tree is complete
 * @tree: pointer to root
 * @index: idx
 * @size: node no
 * Return: 1 complete, 0 if not complete/null
 */
int btic_helper(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);
	if (index >= size)
		return (0);
	return (btic_helper(tree->left, 2 * index + 1, size)
		&& btic_helper(tree->right, 2 * index + 2, size));

}
/**
 * binary_tree_size - measures tree size
 * @tree: obj
 *
 * Return: tree size, 0 if NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}


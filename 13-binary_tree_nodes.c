#include "binary_trees.h"

/**
 * binary_tree_nodes - count node with one binary tree
 * @tree: numbers nodes
 *
 * Return: no of nodes counted, 0 if NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree || (!tree->left && !tree->right))
		return (0);

	return (binary_tree_size(tree) - binary_tree_leaves(tree));

}
/**
 * binary_tree_size - calculates binary tree
 * @tree: tree to calc size
 *
 * Return: tree size, 0 if NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
/**
 * binary_tree_leaves - numbers leaves
 * @tree: tree to enumerate
 *
 * Return: no leaves, 0 if NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)

{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}

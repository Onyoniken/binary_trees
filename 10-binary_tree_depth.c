#include "binary_trees.h"

/**
 * binary_tree_depth - calculates depth node
 * @tree: cal depth
 *
 * Return: depth of node, 0 if NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t d = 0;

	if (!tree)
		return (0);

	while (tree->parent)
	{
		d++;
		tree = tree->parent;
	}
	return (d);
}

#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if leaf
 * @node: node to be checked
 *
 * Return: 1 if leaf, 0 if not leaf, 0 if not NULL
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	return ((!node || node->left || node->right) ? 0 : 1);
}

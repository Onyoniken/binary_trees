#include "binary_trees.h"

/**
 * binary_tree_is_root - checks whether a node is a root
 * @node: node to check
 *
 * Return: 1 if node s root, 0 if node is not root, 0 if node is NULL
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	return ((!node || node->parent) ? 0 : 1);
}

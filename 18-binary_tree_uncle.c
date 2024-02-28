#include "binary_trees.h"
/**
 * binary_tree_uncle - looks for uncle of node
 * @node: pointer to node
 *
 * Return: pointer to uncle node, NULL with no uncle.
 *
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);
	return (binary_tree_sibling(node->parent));
}
/**
 * binary_tree_sibling - locates sibling node
 * @node: pointer to node
 *
 * Return: pointer to sibling node, NULL if parent, node are NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);
	if (node == node->parent->left)
		return (node->parent->right);
	return (node->parent->left);
}

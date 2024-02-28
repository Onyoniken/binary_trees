#include "binary_trees.h"

/**
 * binary_tree_insert_right - insert node as right child
 *
 * @parent: pointer to node to isert right node
 * @value: value to store in new node
 * Description: if a parent has a right child, new node takes its place
 *
 * Return: pointer to created node, or null on failure if parent is null
 *
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (!parent)
		return (NULL);

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);
	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = parent->right;
	parent->right = new;
	if (new->right)
		new->right->parent = new;
	return (new);
}

#include "binary_trees.h"

/**
 * binary_tree_insert_left - insert node as the left-child
 *
 * @parent: pointer to node to insert left_child
 * @value:  stores node
 * Description - if a parent has a left_child, new node must take its place,
 *
 * Return: pointer to created node, or null on failure if parent is null
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (!parent)
		return (NULL);
	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->right = NULL;
	new->left = parent->left;
	parent->left = new;
	if (new->left)
		new->left->parent = new;
	return (new);
}

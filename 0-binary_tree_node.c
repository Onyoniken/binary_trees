#include "binary_trees.h"

/**
 * binary_tree_node - creates a tree node
 *
 * @parent: pointer to the parent node
 * @value: value to put new node
 * Return: pointer to node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	/* declare node in data */
	binary_tree_t *newNode;

	/* allocate memory space for that node */
	newNode = (binary_tree_t *)malloc(sizeof(binary_tree_t));

	if (newNode == NULL)
	{
		return (NULL);
	}

	/* assign values to properties of node*/
	newNode->parent = parent;
	newNode->n = value;
	newNode->left = NULL;
	newNode->right = NULL;

	/* return to pointer of node */
	return (newNode);
}

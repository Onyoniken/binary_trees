#include "binary_trees.h"
/**
 * array_to_bst - main function building BST from an array
 * @array: pointer to the first element
 * @size: no ef elements in an array
 * Return: pointer to root node/ null if fails
 */
bst_t *array_to_bst(int *array, size_t size)
{
	unsigned int k;
	bst_t *root = NULL;

	for (k = 0; k < size; k++)
		bst_insert(&root, array[k]);

	return (root);
}

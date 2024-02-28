#include "binary_trees.h"

/**
 * array_to_avl - main function from array
 * @array: array to create from
 * @size: size for array
 *
 * Return: pointer to root node NULL upon failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	unsigned int k;
	avl_t *root = NULL;

	for (k = 0; k < size; k++)
		avl_insert(&root, array[k]);

	return (root);
}

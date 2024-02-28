#include "binary_trees.h"
/**
 * array_to_heap - main function to build MBH
 * @array: pointer to the first element
 * @size: element no in an array
 *
 * Return: pointer to root node, NULL on failure
 *
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int k;
	heap_t *j = NULL;

	for (k = 0; k < size; k++)
		heap_insert(&j, array[k]);

	return (j);
}

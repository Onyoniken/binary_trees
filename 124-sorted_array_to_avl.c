#include "binary_trees.h"

/**
 * sorted_array_to_avl - main function that buids avl from any array
 * @array: pointer to first element
 * @size: no of elements in array
 *
 * Return: pointer to root node, NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *t = NULL;
	size_t m;

	if (!array)
		return (NULL);
	m = (size - 1) / 2;
	t = binary_tree_node(NULL, array[m]);

	sata_helper(&t, array, -1, m);
	sata_helper(&t, array,  m, size);

	return (t);
}
/**
 * sata_helper - main function that builds AVL from tree array
 * @root: pointer to root node
 * @array: pointer to first element
 * @lo: lower index
 * @hi: upper index
 */
void sata_helper(avl_t **root, int *array, size_t lo, size_t hi)
{
	avl_t *a = NULL;
	size_t m;

	if (hi - lo > 1)
	{
		m = (hi - lo) / 2 + lo;
		a = binary_tree_node(*root, array[m]);
		if (array[m] > (*root)->n)
			(*root)->right = a;
		else if (array[m] < (*root)->n)
			(*root)->left = a;
		sata_helper(&a, array, lo, m);
		sata_helper(&a, array, m, hi);
	}
}

#include "binary_trees.h"

/**
 * tree_size - main functio to measure heights of binary tree
 * @tree: obj
 *
 * Return: Height / 0ig NULL
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t a = 0;
	size_t b = 0;

	if (!tree)
		return (0);

	if (tree->left)
		a = 1 + tree_size(tree->left);

	if (tree->right)
		b = 1 + tree_size(tree->right);
	return (a + b);

}
/**
 * heap_to_sorted_array - main function converts BMH
 * @heap: pointer to root node
 * @size: address to store size array
 *
 * Return: generated array / NULL on failure
 *
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int k, *b = NULL;

	if (!heap || !size)
		return (NULL);

	*size = tree_size(heap) + 1;

	b = malloc(sizeof(int) * (*size));

	if (!b)
		return (NULL);

	for (k = 0; heap; k++)
		b[k] = heap_extract(&heap);

	return (b);
}

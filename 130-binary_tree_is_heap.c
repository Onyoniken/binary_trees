#include "binary_trees.h"

/**
 * binary_tree_is_heap - main function that validates max binary heap
 * @tree: pointer to root node
 *
 * Return: 1 if tree is valid max binary heap, 0 null
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (btih_helper(tree));
}
/**
 * btih_helper - main function that ascertains valid Max Binary Heap
 * @tree: pointer to root node
 *
 * Return: 1 if valid max binary heap, 1 if null, 0 otherwise
 */
int btih_helper(const binary_tree_t *tree)
{
	if (!tree)
		return (1);
	if (!binary_tree_is_complete(tree))
		return (0);
	if (tree->left)
		if (tree->left->n > tree->n)
			return (0);
	if (tree->right)
		if (tree->right->n > tree->n)
			return (0);
	return (btih_helper(tree->left) && btih_helper(tree->right));
}
/**
 * binary_tree_is_complete - main function checks if binary tree is complete
 * @tree: pointer to root node
 * Return: 1 if  complete, 0 if not or NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t s;

	if (!tree)
		return (0);
	s = binary_tree_size(tree);

	return (btic_helper(tree, 0, s));
}
/**
 * btic_helper - main function that checks if binary tree is complete
 * @tree: pointer to root node
 * @index: node to check
 * @size: no of nodes
 *
 * Return: 1 if complete, 0 if not/NULL
 */
int btic_helper(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);
	if (index >= size)
		return (0);

	return (btic_helper(tree->left, 2 * index + 1, size)
		&& btic_helper(tree->right, 2 * index + 2, size));

}
/**
 * binary_tree_size - measures binary tree size
 * @tree: obj
 *
 * Return: tree size/ 0 if NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

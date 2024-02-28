#include "binary_trees.h"

/**
 * binary_trees_ancestor - lowest common ancestor
 * @first: pointer of first node
 * @second: pointer of second node
 * Return: pointer to ancestor node, NULL if no ancestor node
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	size_t a, b;

	if (!first || !second)
		return (NULL);

	a = binary_tree_depth(first);
	b = binary_tree_depth(second);

	while (a > b)
	{
		first = first->parent;
		a--;
	}
	while (b > a)
	{
		second = second->parent;
		b--;
	}
	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}
	return ((binary_tree_t *)first);

}
/**
 * binary_tree_depth - calculates depth node
 * @tree: obj
 *
 * Return: depth of node, 0 if NULL
 *
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t a = 0;

	if (!tree)
		return (0);

	while (tree->parent)
	{
		a++;
		tree = tree->parent;
	}
	return (a);
}

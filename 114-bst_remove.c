#include "binary_trees.h"
/**
 * successor - main function
 * @node: obj
 * Return: min value of tree
 *
 */
int successor(bst_t *node)
{
	int l = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		l = successor(node->left);
		if (l == 0)
		{
			return (node->n);
		}
		return (l);
	}
}
/**
 * two_children - main function to get next successor
 * @root: node with two children
 * Return: value found
 */
int two_children(bst_t *root)
{
	int a = 0;

	a = successor(root->right);
	root->n = a;
	return (a);

}
/**
 * remove_type - main function that removes node
 * @root: node to remove
 * Return: 0 if no children
 */
int remove_type(bst_t *root)
{
	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
		return (two_children(root));
}
/**
 * bst_remove - remove node from BST tree
 * @root: tree root
 * @value: node with value to remove
 * Return: changed tree
 *
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int t = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->right, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		t = remove_type(root);
		if (t != 0)
			bst_remove(root->right, t);
	}
	else
		return (NULL);
	return (root);
}

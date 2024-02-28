#include "binary_trees.h"

/**
 * bal - main function
 * @tree: tree to sail through
 * Return: factor
 */
void bal(avl_t **tree)
{
	int a;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	bal(&(*tree)->left);
	bal(&(*tree)->right);
	a = binary_tree_balance((const binary_tree_t *)*tree);
	if (a > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (a < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}
/**
 * successor - main function to get next successor
 * @node: obj
 * Return: min value tree
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
 * remove_type - main function
 * @root: param 1
 * Return: 0 with no children
 */
int remove_type(bst_t *root)
{
	int b = 0;

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
	{
		b = successor(root->right);
		root->n = b;
		return (b);
	}
}
/**
 * bst_remove - removes node from BST
 * @root: tree root
 * @value: node with value to remove
 * Return: changed tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int t = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
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
/**
 * avl_remove - main function that removes node
 * @root: param 1
 * @value: param 2
 * Return: changed tree
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *) bst_remove((bst_t *) root, value);

	if (root_a == NULL)
		return (NULL);
	bal(&root_a);
	return (root_a);
}

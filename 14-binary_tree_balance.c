#include "binary_trees.h"

/**
 * binary_tree_balance - Measures balance of a tree
 * @tree:  pointer to the root node of the tree
 * to measure the balance factor
 * Return:returns balanced factor or 0
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int r = 0, l = 0, sum = 0;

	if (tree)
	{
		l = ((int)binary_tree_height(tree->left));
		r = ((int)binary_tree_height(tree->right));
		sum = l - r;
	}
	return (sum);
}

/**
 * binary_tree_heights - Measures height of a binary tree
 * @tree: ptr to the node of the tree
 * Return: returns the  height
 */

size_t binary_tree_heights(const binary_tree_t *tree)
{
	size_t l = 0;
	size_t r = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			l = tree->left ? 1 + binary_tree_height(tree->left) : 1;
			r = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		}
		return ((l > r) ? l : r);
	}
}

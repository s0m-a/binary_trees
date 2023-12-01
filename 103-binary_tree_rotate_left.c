#include "binary_trees.h"

/**
 * binary_tree_rotate_left -  performs a left-rotation on a binary tree
 * @tree: ptr to the root node of the tree to rotate
 * Return:ptr to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *rotate;

	if (tree == NULL || tree->right == NULL)
	{
		return (NULL);
	}
	rotate = tree->right;
	tree->right = rotate->left;
	if (rotate->left != NULL)
	{
		rotate->left->parent = tree;
	}
	rotate->left = tree;
	rotate->parent = tree->parent;
	tree->parent = rotate;
	return (rotate);
}

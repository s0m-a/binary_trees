#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: ptr to the root node of the tree to rotate
 * Return: return a ptr to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *rotate;

	if (tree == NULL || tree->left == NULL)
	{
		return (NULL);
	}
	rotate = tree->left;
	tree->left = rotate->right;
	if (rotate->right != NULL)
	{
		rotate->right->parent = tree;
	}
	rotate->right = tree;
	rotate->parent = tree->parent;
	tree->parent = rotate;
	return (rotate);
}

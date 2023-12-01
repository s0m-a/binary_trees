#include "binary_trees.h"

/**
 * binary_tree_levelorder - traverse a binary tree using level-order
 * @tree: tree been traversed
 * @func: ptr to a func to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t lvl, maxlvl;

	if (!tree || !func)
		return;

	maxlvl = binary_tree_height(tree) + 1;

	for (lvl = 1; lvl <= maxlvl; lvl++)
		postO(tree, func, lvl);
}

/**
 * postO - traverse a binary tree using post-order
 * @tree:tree been traversed
 * @func: ptr to a func to call for each node
 * @lvl: level of the tree to call func
 */
void postO(const binary_tree_t *tree, void (*func)(int), size_t lvl)
{
	if (lvl == 1)
		func(tree->n);
	else
	{
		postO(tree->left, func, lvl - 1);
		postO(tree->right, func, lvl - 1);
	}
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: tree to measure the height of
 *
 * Return: height of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t hL = 0;
	size_t hR = 0;

	if (!tree)
		return (0);

	hL = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	hR = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (hL > hR ? hL : hR);
}

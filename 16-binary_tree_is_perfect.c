#include "binary_trees.h"


/**
 *powR - calc value of x raised to the power of y
 *@x: value to expo
 *@y: power to raise x to
 *Return: returns x to the power of y, or -1
 */

int powR(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	else
		return (x * powR(x, y - 1));

}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: tree to measure the size of
 * Return: size of the tree or 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * binary_tree_height - gets the height of a binary tree
 * @tree: tree to measure the height
 * Return: height of the tree or 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t h_l = 0;
	size_t h_r = 0;

	if (!tree)
		return (0);

	h_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	h_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (h_l > h_r ? h_l : h_r);
}

/**
 * binary_tree_is_perfect -checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return:returns 0 is tree is null
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t hgt = 0, node = 0, power = 0;

	if (!tree)
		return (0);

	if (!tree->right && !tree->left)
		return (1);

	hgt = binary_tree_height(tree);
	node = binary_tree_size(tree);

	power = (size_t)powR(2, hgt + 1);
	return (power - 1 == node);
}

#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node
 * @tree: node to calculate the depth of
 * Return: depth of the node or 0
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t dep = 0;

	if (!tree)
		return (0);

	while (tree->parent)
	{
		dep++;
		tree = tree->parent;
	}

	return (dep);
}

/**
 * binary_trees_ancestor -finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the lowest common ancestor
 * node of the two given nodes or  0
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	size_t depthF, depthS;

	if (!first || !second)
		return (NULL);

	depthF = binary_tree_depth(first);
	depthS = binary_tree_depth(second);

	while (depthF > depthS)
	{
		first = first->parent;
		depthF--;
	}
	while (depthS > depthF)
	{
		second = second->parent;
		depthS--;
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

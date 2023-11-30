#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: pointer to the node to insert the right-child in
 * @value: value to store in the new node
 * Return: the created node, or NULL on failure or if parent is NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *nodeR;

	if (!parent)
		return (NULL);

	nodeR = malloc(sizeof(binary_tree_t));
	if (!nodeR)
		return (NULL);

	nodeR->n = value;
	nodeR->parent = parent;
	nodeR->left = NULL;
	nodeR->right = parent->right;
	parent->right = nodeR;
	if (nodeR->right)
		nodeR->right->parent = nodeR;
	return (nodeR);
}

#include "binary_trees.h"

/**
 * binary_tree_insert_left -inserts a node as the left-child of another node
 * @parent: pointer to the node to insert the left-child in
 * @value:  value to store in the new node
 * Return:  a pointer to the created node,
 * or NULL on failure or if parent is NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *nodeL;

	if (!parent)
		return (NULL);

	nodeL = malloc(sizeof(binary_tree_t));
	if (!nodeL)
		return (NULL);

	nodeL->n = value;
	nodeL->parent = parent;
	nodeL->right = NULL;
	nodeL->left = parent->left;
	parent->left = nodeL;
	if (nodeL->left)
		nodeL->left->parent = nodeL;
	return (nodeL);
}

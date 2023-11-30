#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: - pointer to the parent node
 * @value: - value to insert in the new node
 * Return: ptr to the new node
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode;

	newNode = (binary_tree_t *)malloc(sizeof(binary_tree_t));

	if (newNode == NULL)
	{
		return (NULL);
	}

	newNode->parent = parent;
	newNode->n = value;
	newNode->left = NULL;
	newNode->right = NULL;

	return (newNode);
}

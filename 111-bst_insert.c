#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree:double pointer to the root node of the BST to insert the value
 * @value:value to store in the node to be inserted
 * Return: A pointer to the created node or 0
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *temp = NULL;
	bst_t *sec = NULL;
	bst_t *new = NULL;

	if (!tree)
		return (NULL);
	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));

	temp = *tree;
	while (temp)
	{
		sec = temp;
		if (value < temp->n)
			temp = temp->left;
		else if (value > temp->n)
			temp = temp->right;
		else if (value == temp->n)
			return (NULL);
	}

	new = binary_tree_node(NULL, value);
	if (sec == NULL)
		sec = new;
	else if (value < sec->n)
	{
		sec->left = new;
		new->parent = sec;
	}
	else
	{
		sec->right = new;
		new->parent = sec;
	}

	return (new);
}

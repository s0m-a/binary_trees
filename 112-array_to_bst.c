#include "binary_trees.h"

/**
 * array_to_bst - builds a Binary Search Tree from an array
 * @array: pointer to the first element of the array
 * @size:  number of element in the array
 * Return: A pointer to the root node of the created
 * or 0
 */
bst_t *array_to_bst(int *array, size_t size)
{
	unsigned int x;
	bst_t *root = NULL;

	for (x = 0; x < size; x++)
		bst_insert(&root, array[x]);

	return (root);
}

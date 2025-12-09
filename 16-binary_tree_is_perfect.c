#include "binary_trees.h"

/**
 * find_depth - Finds depth of the leftmost leaf
 * @tree: Pointer to the tree
 *
 * Return: Depth of the leftmost leaf
 */
int find_depth(const binary_tree_t *tree)
{
	int d = 0;

	while (tree)
	{
		d++;
		tree = tree->left;
	}

	return (d);
}

/**
 * is_perfect_recursive - Checks recursively if tree is perfect
 * @tree: Pointer to current node
 * @depth: Depth of first leaf
 * @level: Current level in the tree
 *
 * Return: 1 if perfect, 0 otherwise
 */
int is_perfect_recursive(const binary_tree_t *tree, int depth, int level)
{
	if (!tree)
        	return (1);

	if (!tree->left && !tree->right)
		return (depth == level + 1);

	if (!tree->left || !tree->right)
		return (0);

	return (is_perfect_recursive(tree->left, depth, level + 1) &&
is_perfect_recursive(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root of the tree
 *
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int depth;

	if (!tree)
		return (0);

	depth = find_depth(tree);

	return (is_perfect_recursive(tree, depth, 0));
}

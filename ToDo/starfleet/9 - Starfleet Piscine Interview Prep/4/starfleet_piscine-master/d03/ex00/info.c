#include <stdlib.h> //malloc, free, exit...
#include <math.h>
#include <limits.h>
#include "header.h"

int get_depth(struct s_node *root)
{
	if (!root)
		return 0;
	return fmax(get_depth(root->left), get_depth(root->right)) + 1;
}

int get_height(struct s_node *root)
{
	if (!root || (!root->left && !root->right))
		return 0;

	return fmax(get_height(root->left), get_height(root->right)) + 1;
}

int checkBal(struct s_node *root)
{
	if(!root)
		return 1;
	if(abs(get_depth(root->left) - get_depth(root->right)) <= 1 &&
		checkBal(root->left) &&
		checkBal(root->right))
		return 1;
	return 0;
}

int checkBST(struct s_node *root)
{
	if(!root)
		return 1;
	else if(root->left && root->left->value > root->value)
		return 0;
	else if (root->right && root->right->value <= root->value)
		return 0;
	return checkBST(root->left) && checkBST(root->right);
}

int count(struct s_node *root)
{
	if (!root)
		return 0;
	return count(root->left) + count(root->right) + 1;
}


int get_min(struct s_node *root)
{
	if(!root)
		return INT_MAX;
	return fmin(root->value, fmin(get_min(root->left), get_min(root->right)));
}

int get_max(struct s_node *root)
{
	if(!root)
		return INT_MIN;
	return fmax(root->value, fmax(get_max(root->left), get_max(root->right)));
}

struct s_info   getInfo(struct s_node *root)
{
	struct s_info info;
	info.min = get_min(root);
	info.max = get_max(root);
	info.elements = count(root);
	info.height = get_height(root);
	info.isBST = checkBST(root);
	info.isBalanced = checkBal(root);
	return info;
}
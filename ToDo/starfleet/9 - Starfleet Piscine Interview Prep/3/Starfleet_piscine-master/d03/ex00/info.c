#include "header.h"
#include <stdio.h>
#include <stdlib.h>

int findmax(struct s_node *root)
{
	int left;
	int right;
	int rootret;
	struct s_node *curr;

	left = 0;
	right = 0;
	curr = root;
	rootret = curr->value;
	if (root->left)
		left = findmax(root->left);
	if (root->right)
		right = findmax(root->right);
	if (left > rootret)
		rootret = left;
	if (right > rootret)
		rootret = right;
	return rootret;
}

int findmin(struct s_node *root)
{
	int left;
	int right;
	int rootret;
	struct s_node *curr;

	left = root->value;
	right = root->value;
	curr = root;
	rootret = curr->value;
	if (root->left)
		left = findmin(root->left);
	if (root->right)
		right = findmin(root->right);
	if (left < rootret)
		rootret = left;
	if (right < rootret)
		rootret = right;
	return rootret;
}

int findelemets(struct s_node *root)
{
	if (root == NULL)
		return 0;
	else
		return(findelemets(root->left) + 1 + findelemets(root->right));
}

int findheight(struct s_node *root)
{
	if (!root)
		return 0;
	else
	{
		int lh = findheight(root->left);
		int rh = findheight(root->right);
		if (lh > rh)
			return (lh + 1);
		else if (rh > lh)
			return (rh + 1);
		else
			return(rh + 1);
	}
}

int isbal(struct s_node *root)
{
	int lh;
	int rh;

	if (!root)
		return 1;
	lh = findheight(root->left);
	rh = findheight(root->right);
	if (abs(rh - lh) <= 1 && isbal(root->left) && isbal(root->right))
		return 1;
	return 0;
}

int isBST(struct s_node *root)
{

	if (root == NULL)
		return 1;
	if (root->left && findmax(root->left) > root->value)
		return 0;
	if (root->right && findmin(root->right) < root->value)
		return 0;
	if (!isBST(root->left) || !isBST(root->right))
		return 0;
	return 1;
}

struct s_info getInfo(struct s_node *root)
{
	struct s_info ret;

	ret.max = findmax(root);
	ret.min = findmin(root);
	ret.elements = findelemets(root);
	ret.height = findheight(root);
	ret.isBalanced = isbal(root);
	ret.isBST = isBST(root);

	return ret;
}

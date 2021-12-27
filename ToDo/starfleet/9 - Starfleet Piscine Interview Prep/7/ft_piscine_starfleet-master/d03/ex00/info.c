#include "header.h"

int				findMin(struct s_node *root)
{
	int res;
	int	lres;
	int rres;

	if (root == NULL)
		return (INT_MAX);
	
	res = root->value;
	lres = findMin(root->left);
	rres = findMin(root->right);
	if (lres < res)
		res = lres;
	if (rres < res)
		res = rres;
	return (res);
}

int				findMax(struct s_node *root)
{
	int res;
	int	lres;
	int rres;

	if (root == NULL)
		return (INT_MIN);
	
	res = root->value;
	lres = findMax(root->left);
	rres = findMax(root->right);
	if (lres > res)
		res = lres;
	if (rres > res)
		res = rres;
	return (res);
}

int				findSize(struct s_node *root)
{
	if (root == NULL)
		return (0);
	else
		return (1 + findSize(root->left) + findSize(root->right));
}

int				isBST(struct s_node *root, int min, int max)
{
	if (root == NULL)
		return (1);
	else if (root->value > max || root->value < min)
		return (0);
	else
		return (isBST(root->left, min, root->value) &&
				isBST(root->right, root->value + 1, max));
}

int				isBalanced(struct s_node *root, int *height)
{
	int l_height;
	int r_height;
	int	l_bal;
	int	r_bal;

	if (root == NULL)
	{
		*height = 0;
		return (1);
	}
	l_bal = isBalanced(root->left, &l_height);
	r_bal = isBalanced(root->right, &r_height);
	*height = fmax(l_height, r_height) + 1;
	return (r_bal && l_bal && abs(l_height - r_height) < 2);
}

struct s_info	getInfo(struct s_node *root)
{
	struct s_info info;

	info.min        = findMin(root);
	info.max        = findMax(root);
	info.elements   = findSize(root);
	info.isBST      = isBST(root, INT_MIN, INT_MAX);
	info.isBalanced = isBalanced(root, &(info.height));
	return (info);
}

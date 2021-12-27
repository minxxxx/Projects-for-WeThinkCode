#include "header.h"

struct s_node *DaC_BST(int *arr, int l, int r)
{
	struct s_node	*root;
	int				m;

	if (l > r)
		return (NULL);
	root = (struct s_node*)malloc(sizeof(struct s_node));
	m = (l + r) / 2;
	root->value = arr[m];
	root->left = DaC_BST(arr, l, m - 1);
	root->right = DaC_BST(arr, m + 1, r);
	return (root);
}


struct s_node *createBST(int *arr, int n)
{
	return (DaC_BST(arr, 0, n - 1));
}

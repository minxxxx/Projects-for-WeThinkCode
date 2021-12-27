#include "header.h"

int	getHeight(struct s_node *root)
{
	if (root == NULL)
		return (0);
	else 
		return(fmax(getHeight(root->left), getHeight(root->right)) + 1);
}

int findSize(struct s_node *root)
{
	if (root == NULL)
		return (0);
	else
		return (1 + findSize(root->left) + findSize(root->right));
}

void	add_to_arr(struct s_node **arr, struct s_node *root, int level, int *i)
{
	if (level == 0)
	{
		arr[*i] = root;
		(*i)++;
	}
	else
	{
		add_to_arr(arr, root->right, level - 1, i);
		add_to_arr(arr, root->left, level - 1, i);
	}
}


struct s_node **to_arr(struct s_node *root, int size)
{
	int i;
	int h;
	struct s_node **arr;

	h = getHeight(root);
	i = 0;
	arr = (struct s_node**)malloc(sizeof(struct s_node*) * size);
	for (int j = 0; j < h; j++)
		add_to_arr(arr, root, j, &i);
	return (arr);
}

void	percolate_up(struct s_node **arr, int i, int size)
{
	struct s_node *tmp;
	int li;
	int ri;
	int largest;

	while (2 * i + 1 < size)
	{
		ri = 2 * i + 1;
		li = 2 * i + 2;
		largest = (arr[li]->value > arr[ri]->value ? li : ri);
		if (arr[i]->value < arr[largest]->value)
		{
			tmp = arr[i];
			arr[i] = arr[largest];
			arr[largest] = tmp;
			i = largest;
		}
		else
			break ;
	}
}


void saveTheSequoia(struct s_node **root)
{
	struct s_node **arr;
	int size;
	int lj;
	int rj;

	size = findSize(*root);
	arr = to_arr(*root, size);
	for (int i = size - 1; i >= 0; i--)
		percolate_up(arr, i, size);
	for (int j = 0; j < size; j++)
	{
		rj = 2 * j + 1;
		lj = 2 * j + 2;
		arr[j]->left = (lj >= size ? NULL : arr[lj]);
		arr[j]->right = (rj >= size ? NULL : arr[rj]);
	}
	*root = arr[0];
}

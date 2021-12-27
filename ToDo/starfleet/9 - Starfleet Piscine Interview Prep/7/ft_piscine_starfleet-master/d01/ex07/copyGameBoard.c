#include "header.h"

struct s_node *cloneGameBoard(struct s_node *node)
{
	int				len;
	struct s_node	*list_iter;
	struct s_node	*node_arr;

	list_iter = node;
	len = 0;
	while (list_iter)
	{
		len++;
		list_iter = list_iter->next;
	}

	node_arr = (struct s_node*)malloc(sizeof(struct s_node) * len);
	list_iter = node;
	for (int i = 0; i < len; i++)
	{
		node_arr[i].value = i;
		node_arr[i].next = (i + 1 == len ? NULL : node_arr + (i + 1));
		if (list_iter->random)
			node_arr[i].random = node_arr + (list_iter->random->value);
		else
			node_arr[i].random = NULL;
		list_iter = list_iter->next;
	}

	return (node_arr);
}

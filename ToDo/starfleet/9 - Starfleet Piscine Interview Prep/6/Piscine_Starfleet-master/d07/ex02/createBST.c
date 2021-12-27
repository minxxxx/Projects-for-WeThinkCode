/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createBST.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 06:59:06 by smonroe           #+#    #+#             */
/*   Updated: 2019/01/18 07:13:40 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_node *new(int value)
{
	struct s_node *ret = calloc(1, sizeof *ret);
	ret->value = value;
	return ret;
}

struct s_node *bst(int *arr, int start, int end)
{
	if (!arr || start > end)
		return 0;
	int mid = start + ((end - start) / 2);
	struct s_node *node = new(arr[mid]);
	node->left = bst(arr, start, mid - 1);
	node->right = bst(arr, mid + 1, end);
	return node;
}

struct s_node *createBST(int *arr, int n)
{
	struct s_node *root = bst(arr, 0, n - 1);
	return root;
}

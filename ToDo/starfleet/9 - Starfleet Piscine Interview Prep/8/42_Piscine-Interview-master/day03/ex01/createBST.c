/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createBST.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 10:45:46 by jaleman           #+#    #+#             */
/*   Updated: 2017/08/04 10:45:47 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <stdlib.h>

struct s_node		*createNode(int val)
{
	struct s_node	*node;

	node = (struct s_node *)malloc(sizeof(struct s_node));
	node->value = val;
	node->left = NULL;
	node->right =  NULL;
	return (node);
}

struct s_node		*buildTree(int *arr, int start, int end)
{
	int				mid;
	struct s_node	*tree;

	tree = NULL;
	if (start < end)
	{
		mid = start + (end - start) / 2;
		tree = createNode(arr[mid]);
		tree->left = buildTree(arr, start, mid - 1);
		tree->right = buildTree(arr, mid + 1, end);
	}
	return (tree);
}

struct s_node		*createBST(int *arr, int n)
{
	return (buildTree(arr, 0, n));
}

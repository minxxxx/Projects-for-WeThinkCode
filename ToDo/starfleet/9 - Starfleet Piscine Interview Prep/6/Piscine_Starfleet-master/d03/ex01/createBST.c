/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createBST.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 21:07:05 by smonroe           #+#    #+#             */
/*   Updated: 2019/01/10 22:38:19 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_node *new(int n)
{
	struct s_node *new = malloc(sizeof(*new));
	if (!new)
		return 0;
	new->left = new->right = 0;
	new->value = n;
	return new;
}

struct s_node *bst(int *arr, int start, int end)
{
	if (start > end)
		return 0;
	int mid = start + ((end - start) / 2);
	struct s_node *tmp = new(arr[mid]);
	tmp->left = bst(arr, start, mid - 1);
	tmp->right = bst(arr, mid + 1, end);
	return tmp;
}

struct s_node *createBST(int *arr, int n) { return bst(arr, 0, n - 1); }

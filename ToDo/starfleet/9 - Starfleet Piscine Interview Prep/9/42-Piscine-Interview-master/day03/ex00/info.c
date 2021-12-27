/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 17:09:11 by amontano          #+#    #+#             */
/*   Updated: 2019/01/11 17:09:13 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_info   getInfo(struct s_node *root)
{
	t_info	info;

	if (root)
	{
		info.min = root->value;
		info.max = root->value;
		info.elements = 0;
		info.height = 0;
		info.isBST = 1;
		info.isBalanced = 1;
		traverse_tree(root, &info, 0);
	}
	else
	{
		info.height = -1;
		info.elements = 0;
	}
	return (info);
}

static int check_if_bst(t_node *root)
{
	if (root->left && root->left->value > root->value)
		return (0);
	if (root->right && root->right->value <= root->value)
		return (0);
	return (1);
}

static int check_if_balanced(t_node *root)
{
	int left_ht = -1;
	int right_ht = -1;

	if (root->left)
		left_ht = height_tree(root->left, 0);
	if (root->right)
		right_ht = height_tree(root->right, 0);
	if ( (left_ht - right_ht > 1) || (left_ht - right_ht < -1) )
		return (0);
	else
		return (1);
		
}

int	height_tree(t_node *root, int h)
{
	int ht = -1;

	if (!root)
		return (-1);
	if (root->left)
		ht = height_tree(root->left, h + 1);
	if (root->right)
		ht = height_tree(root->right, h + 1);
	return (ht > h ? ht : h);
}

void traverse_tree(t_node *root, t_info *info, int h)
{
	if (root)
	{
		info->height = (info->height < h) ? h : info->height;
		info->max = (info->max < root->value) ? root->value : info->max;
		info->min = (info->min > root->value) ? root->value : info->min;
		info->elements++;
		if (!check_if_bst(root))
			info->isBST = 0;
		if (!check_if_balanced(root))
			info->isBalanced = 0;
	}
	if (root->left)
		traverse_tree(root->left, info, h + 1);
	if (root->right)
		traverse_tree(root->right, info, h + 1);
}
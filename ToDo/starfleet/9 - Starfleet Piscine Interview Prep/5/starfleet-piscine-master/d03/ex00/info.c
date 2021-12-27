/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 09:42:04 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/27 11:02:56 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <limits.h>
#include <stdlib.h>

int	getMin(struct s_node *root)
{
	if (!root)
		return (INT_MAX);
	else
	{
		int val = root->value;
		int	left_val = getMin(root->left);
		int	right_val = getMin(root->right);
		if (left_val < val)
			val = left_val;
		if (right_val < val)
			val = right_val;
		return (val);
	}
}

int	getMax(struct s_node *root)
{
	if (!root)
		return (INT_MIN);
	else
	{
		int val = root->value;
		int	left_val = getMax(root->left);
		int	right_val = getMax(root->right);
		if (left_val > val)
			val = left_val;
		if (right_val > val)
			val = right_val;
		return (val);
	}
}

int	getElements(struct s_node *root, int count)
{
	if (!root)
		return (0);
	else
		return (getElements(root->right, count) + getElements(root->left, count) + 1);
}

int	getHeight(struct s_node *root)
{
	if (!root)
		return (-1);
	else
	{
		int leftDepth = getHeight(root->left);
		int rightDepth = getHeight(root->right);
		return ((leftDepth > rightDepth) ? leftDepth + 1 : rightDepth + 1);
	}
}

int	checkIfBST(struct s_node *root)
{
	if (!root)
		return (1);
	if (root->left && root->left->value > root->value)
		return (0);
	if (root->right && root->right->value < root->value)
		return (0);
	if (!checkIfBST(root->left) || !checkIfBST(root->right))
		return (0);
	return (1);
}

int	checkIfBalanced(struct s_node *root)
{
	if (!root)
		return (1);
	int	left_height = getHeight(root->left);
	int	right_height = getHeight(root->right);
	int	diff = (left_height > right_height) ? left_height - right_height : right_height - left_height;
	if (diff <= 1 && checkIfBalanced(root->left) && checkIfBalanced(root->right))
		return (1);
	else
		return (0);
}

struct s_info   getInfo(struct s_node *root)
{
	struct s_info info;

	info.min = getMin(root);
	info.max = getMax(root);
	info.elements = getElements(root, 0);
	info.height = getHeight(root);
	info.isBST = checkIfBST(root);
	info.isBalanced = checkIfBalanced(root);
	return (info);
}

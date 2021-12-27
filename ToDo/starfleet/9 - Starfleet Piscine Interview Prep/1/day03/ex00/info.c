/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 10:19:19 by jaleman           #+#    #+#             */
/*   Updated: 2017/08/04 10:19:20 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <stdlib.h>

static int			getMax(struct s_node *node)
{
	int				max;

	max = 0;
	if (node)
	{
		if (node->left)
			max = MAX(node->value, getMax(node->left));
		if (node->right)
			max = MAX(node->value, getMax(node->right));
	}
	return (!max ? node->value : max);
}

static int			getMin(struct s_node *node)
{
	int				min;

	min = 0;
	if (node)
	{
		if (node->left)
			min = MIN(node->value, getMin(node->left));
		if (node->right)
			min = MIN(node->value, getMin(node->right));
	}
	return (!min ? node->value : min);
}

static int			getElement(struct s_node *node)
{
	int				element;

	element = 0;
	if (node)
	{
		if (node->left)
			element = getElement(node->left) + 1;
		if (node->right)
			element = getElement(node->right) + 1;
	}
	return (element);
}

static int			getHeight(struct s_node *node)
{
	int				height;

	height = 0;
	if (node)
	{
		height = MAX(getHeight(node->left), getHeight(node->right));
	}
	return (height);
}

static int			isBST(struct s_node *node)
{

	int				ret;

	ret = 1;
	if (node)
	{
		if ((node->left) && (getMax(node->left) > node->value))
			ret = 0;
		else if ((node->right) && (getMin(node->right) <= node->value))
			ret = 0;
		else
			return (isBST(node->left) && isBST(node->right));
	}
	return (ret);
}

static int			isBalanced(struct s_node *node)
{
	int				lh;
	int				rh;
	int				ret;

	ret = 1;
	if (node)
	{
		lh = getHeight(node->left);
		rh = getHeight(node->right);
		ret = (abs(lh - rh) <= 1 \
			&& isBalanced(node->left) && isBalanced(node->right)) ? 1 : 0;
	}
	return (ret);
}

struct s_info		getInfo(struct s_node *root)
{
	struct s_node	*tmp;
	struct s_info	info;

	tmp = root;
	info.max = getMax(root);
	info.min = getMin(root);
	info.elements = getElement(root);
	info.height = getHeight(root);
	info.isBST = isBST(root);
	info.isBalanced = isBalanced(root);
	return (info);
}

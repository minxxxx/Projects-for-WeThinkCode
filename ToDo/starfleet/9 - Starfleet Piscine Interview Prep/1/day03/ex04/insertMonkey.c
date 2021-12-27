/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertMonkey.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 11:39:00 by jaleman           #+#    #+#             */
/*   Updated: 2017/08/04 11:39:01 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <stdlib.h>

static void			swapLeft(struct s_node **n1, struct s_node **n2)
{
	struct s_node	*tmp;

	tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
	tmp = (*n1)->right;
	(*n1)->right = (*n2)->right;
	(*n2)->right = tmp;
	tmp = (*n1)->left;
	(*n1)->left = (*n2)->left;
	(*n2)->left = tmp;
	return ;
}

static void			swapRight(struct s_node **n1, struct s_node **n2)
{
	struct s_node	*tmp;

	tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
	tmp = (*n1)->left;
	(*n1)->left = (*n2)->left;
	(*n2)->left = tmp;
	tmp = (*n1)->right;
	(*n1)->right = (*n2)->right;
	(*n2)->right = tmp;
	return ;
}

static int			isMaxHeap(struct s_node *node)
{
	int				ret;

	ret = 1;
	if (node)
	{
		if (node->left && node->left->value > node->value)
			ret = 0;
		else if (node->right && node->right->value > node->value)
			ret = 0;
		else
			ret = isMaxHeap(node->left) && isMaxHeap(node->right);
	}
	return (ret);
}

static void			maxify(struct s_node **root)
{
	if (*root != NULL)
	{
		while (!isMaxHeap(*root))
		{
			maxify(&((*root)->left));
			if ((*root)->left && (*root)->left->value > (*root)-> value)
				swapLeft(root, &((*root)->left));
			maxify(&((*root)->right));
			if ((*root)->right && (*root)->right->value > (*root)-> value)
				swapRight(root, &((*root)->right));
		}
	}
	return ;
}

static int			countElement(struct s_node *node)
{
	int				ret;

	ret = 0;
	if (node)
	{
		if (node->left)
			ret += countElement(node->left) + 1;
		if (node->right)
			ret += countElement(node->right) + 1;
	}
	return (ret);
}

static void			insertRecord(struct s_node **root, struct s_node *record)
{

	if ((*root)->left == NULL)
	{
		((*root)->left = record);
		return;
	}
	if ((*root)->right == NULL)
	{
		((*root)->right = record);
		return;
	}
	if (countElement((*root)->left) > countElement((*root)->right))
		insertRecord(&(*root)->right, record);
	else
		insertRecord(&(*root)->left, record);
	return ;
}

void				insertMonkey(struct s_node **root, struct s_node *monkey)
{
	insertRecord(root, monkey);
	printBinaryTree(*root);
	maxify(root);
	printBinaryTree(*root);
	return ;
}

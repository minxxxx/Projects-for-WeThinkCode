/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saveTheSequoia.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 11:39:00 by jaleman           #+#    #+#             */
/*   Updated: 2017/08/04 11:39:01 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <stdlib.h>
#include <stdio.h>

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

void	saveTheSequoia(struct s_node **root)
{
	if (*root)
	{
		while (!isMaxHeap(*root))
		{
			saveTheSequoia(&((*root)->left));
			if ((*root)->left && (*root)->left->value > (*root)-> value)
				swapLeft(root, &((*root)->left));
			saveTheSequoia(&((*root)->right));
			if ((*root)->right && (*root)->right->value > (*root)-> value)
				swapRight(root, &((*root)->right));
		}
	}
	return;
}

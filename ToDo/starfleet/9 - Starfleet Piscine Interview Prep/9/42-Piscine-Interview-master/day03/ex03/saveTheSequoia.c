/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saveTheSequoia.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 06:19:56 by amontano          #+#    #+#             */
/*   Updated: 2019/01/12 06:19:57 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void swap_left(t_node **a, t_node **b)
{
	t_node *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	tmp = (*a)->right;
	(*a)->right = (*b)->right;
	(*b)->right = tmp;
	tmp = (*a)->left;
	(*a)->left = (*b)->left;
	(*b)->left = tmp;
}

void	swap_right(t_node **a, t_node **b)
{
	t_node *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	tmp = (*a)->left;
	(*a)->left = (*b)->left;
	(*b)->left = tmp;
	tmp = (*a)->right;
	(*a)->right = (*b)->right;
	(*b)->right = tmp;
}

int is_maxHeap(t_node *root)
{
	int boo;
	boo = 1;
	if (root)
	{
		if (root->left && root->left->value > root->value)
			boo = 0;
		else if (root->right && root->right->value > root->value)
			boo = 0;
		else
			boo = (is_maxHeap(root->left) && is_maxHeap(root->right));
	}
	return (boo);
}

void saveTheSequoia(struct s_node **root)
{
	while (!is_maxHeap((*root)))
	{
		saveTheSequoia(&(*root)->left);
		if ((*root)->left && ((*root)->value < (*root)->left->value))
			swap_left(root, &(*root)->left);
		saveTheSequoia(&(*root)->right);
		if ((*root)->right && (*root)->value < (*root)->right->value)
			swap_right(root, &(*root)->right);
	}
}
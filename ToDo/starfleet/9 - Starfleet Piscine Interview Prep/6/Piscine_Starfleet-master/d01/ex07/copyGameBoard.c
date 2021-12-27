/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copyGameBoard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 21:45:56 by smonroe           #+#    #+#             */
/*   Updated: 2019/01/09 21:57:57 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static struct s_node *new(int n)
{
	struct s_node *tmp = malloc(sizeof(*tmp));
	tmp->next = tmp->random = 0;
	tmp->value = n;
	return tmp;
}

struct s_node *cloneGameBoard(struct s_node *node)
{
	struct s_node *cur = node;
	struct s_node *tmp = 0;
	while (cur)
	{
		tmp = cur->next;
		cur->next = new(cur->value);
		cur->next->next = tmp;
		cur = tmp;
	}
	cur = node;
	while (cur)
	{
		if (cur->next)
			cur->next->random = cur->random ? cur->random->next : cur->random;
		cur = cur->next ? cur->next->next : cur->next;
	}
	cur = node;
	tmp = node->next;
	struct s_node *ret = tmp;
	while (cur && tmp)
	{
		cur->next = cur->next ? cur->next->next : cur->next;
		tmp->next = tmp->next ? tmp ->next->next : tmp->next;
		cur = cur->next;
		tmp = tmp->next;
	}
	return ret;
}

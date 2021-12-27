/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 15:36:04 by jcamhi            #+#    #+#             */
/*   Updated: 2017/07/24 15:36:05 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>
#include <libft.h>

long long	ft_rights(t_symbole *elem1, t_symbole *elem2)
{
	if (elem1->poids != elem2->poids)
		return (elem1->poids - elem2->poids);
	if (!elem1->str && !elem2->str)
		return (ft_strcmp("", ""));
	else if (!elem1->str)
		return (ft_strcmp("", elem2->str));
	else if (!elem2->str)
		return (ft_strcmp(elem1->str, ""));
	else
	{
		if (ft_strcmp(elem1->str, elem2->str) != 0)
			return (ft_strcmp(elem1->str, elem2->str));
		else
			return (elem1->value - elem2->value);
	}
	return (0);
}

static int	norme_sort(t_symbole **prev, t_symbole **debut, t_symbole **list)
{
	t_symbole *tmp;

	if (*prev)
		(*prev)->next = (*list)->next;
	if (*list == *debut)
		*debut = (*list)->next;
	tmp = ((*list)->next)->next;
	((*list)->next)->next = *list;
	(*list)->next = tmp;
	return (0);
}

t_symbole	*ft_sort(t_symbole *list)
{
	t_symbole	*debut;
	t_symbole	*prev;
	int			range;

	range = 0;
	debut = list;
	while (!range)
	{
		prev = NULL;
		range = 1;
		while (list && list->next)
		{
			if (ft_rights(list, list->next) > 0)
				range = norme_sort(&prev, &debut, &list);
			prev = list;
			list = list->next;
		}
		list = debut;
	}
	return (debut);
}

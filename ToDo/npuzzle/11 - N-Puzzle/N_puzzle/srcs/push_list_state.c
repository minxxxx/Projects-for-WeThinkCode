/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_list_state.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 06:45:44 by ggroener          #+#    #+#             */
/*   Updated: 2016/11/15 06:45:44 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

static void	insert(t_state_list **list, t_state_list *lst, t_state_list *prv, t_state_list *crt)
{
	if (!prv)
	{
		crt->next = *list;
		*list = crt;
		return;
	}
	else
	{
		crt->next = lst;
		prv->next = crt;
	}
}

static void	push(t_state_list **list, t_state_list *state)
{
	t_state_list *prv;
	t_state_list *lst;

	prv = NULL;
	lst = *list;
	while (lst)
	{
		if (state->state->f <= lst->state->f) // this is better than previous one
		{
			insert(list, lst, prv, state);
			return;
		}
		prv = lst;
		lst = lst->next;
	}
	prv->next = state;
}

void	push_list_state(t_state_list **lst, t_state *state)
{
	t_state_list *new;

	if (!(new = malloc(sizeof(*new))))
	{
		ft_putendl_fd("npuzzle: failed to malloc new state elem", 2);
		exit(EXIT_FAILURE);
	}
	new->next = NULL;
	new->state = state;
	if (*lst == NULL)
	{
		*lst = new;
		return;
	}
	push(lst, new);
}

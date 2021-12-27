/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_list_state.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 06:46:57 by ggroener          #+#    #+#             */
/*   Updated: 2016/11/15 06:46:57 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

void remove_list_state(t_state_list **lst, t_state *state)
{
	t_state_list *tmp;
	t_state_list *ite;
	t_state_list *prv;

	if (!(*lst))
		return;
	if ((*lst)->state == state)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
		return;
	}
	ite = *lst;
	prv = NULL;
	while (ite)
	{
		if (ite->state == state)
		{
			prv->next = ite->next;
			free(ite);
			return;
		}
		prv = ite;
		ite = ite->next;
	}
}

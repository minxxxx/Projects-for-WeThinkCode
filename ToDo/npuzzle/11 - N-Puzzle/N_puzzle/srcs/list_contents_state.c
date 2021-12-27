/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_contents_state.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 06:41:36 by ggroener          #+#    #+#             */
/*   Updated: 2016/11/15 06:41:37 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

int list_contents_state(t_env *env, t_state_list *lst, t_state *state)
{
	t_state_list *tmp;

	tmp = lst;
	while (tmp)
	{
		if (equals_state(env, tmp->state, state))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

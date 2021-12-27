/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list_state.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 06:43:29 by ggroener          #+#    #+#             */
/*   Updated: 2016/11/15 06:43:30 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

void free_list_state(t_state_list *lst)
{
	t_state_list *tmp;
	t_state_list *nxt;

	tmp = lst;
	while (tmp)
	{
		nxt = tmp->next;
		free(tmp);
		tmp = nxt;
	}
}

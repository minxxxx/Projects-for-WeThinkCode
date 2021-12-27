/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <dtedgui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 10:08:18 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/22 11:53:27 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh.h"

int				print_history(t_hist *history)
{
	int			i;
	t_hist		*tmp;

	ft_puts("nw");
	i = 1;
	tmp = history;
	ft_printf("\n%d %s", i, tmp->cmd);
	i++;
	tmp = tmp->prev;
	while (tmp != history)
	{
		ft_printf("\n%d %s", i, tmp->cmd);
		i++;
		tmp = tmp->prev;
	}
	return (i);
}

t_hist			*add_line_to_history(t_hist *history)
{
	t_hist		*new_line;

	if (!(new_line = malloc(sizeof(*new_line))))
		return (NULL);
	new_line->cmd = ft_strdup(g_main_line.cmd);
	new_line->size = g_main_line.size_x;
	new_line->prev = history;
	new_line->next = history->next;
	history->next->prev = new_line;
	history->next = new_line;
	return (history);
}

t_hist			*init_history(t_hist *history)
{
	if (!(history = malloc(sizeof(*history))))
		return (NULL);
	history->cmd = ft_strdup(g_main_line.cmd);
	history->size = g_main_line.size_x;
	history->prev = history;
	history->next = history;
	return (history);
}

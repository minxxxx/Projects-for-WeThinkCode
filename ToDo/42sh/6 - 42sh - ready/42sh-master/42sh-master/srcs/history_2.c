/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

t_history		*create_history_elem(char *content)
{
	struct timeval	tv;
	t_history		*elem;

	elem = (t_history*)mallocp(sizeof(t_history));
	elem->line = ft_strdup(content);
	gettimeofday(&tv, NULL);
	elem->time = (int)tv.tv_sec;
	elem->get_from_file = 0;
	elem->next = NULL;
	elem->prec = NULL;
	return (elem);
}

t_history		*add_history_elem(t_history *list, t_history *elem)
{
	if (list == NULL)
		return (elem);
	if (ft_strequ(elem->line, list->line))
	{
		free(elem->line);
		free(elem);
		return (list);
	}
	list->next = elem;
	elem->prec = list;
	return (elem);
}

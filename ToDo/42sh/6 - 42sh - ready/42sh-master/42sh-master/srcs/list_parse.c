/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:15 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 19:06:03 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

void	init_fd(t_cmd *elem)
{
	if (elem->fd_in->fd == -1)
		elem->fd_in->fd = 0;
	if (elem->fd_out->fd == -1)
		elem->fd_out->fd = 1;
	if (elem->fd_err->fd == -1)
		elem->fd_err->fd = 2;
}

t_cmd	*create_cmd_elem(char *str, int count, t_hc **heredocs)
{
	t_cmd	*elem;

	elem = (t_cmd*)mallocp(sizeof(t_cmd));
	elem->ret = 23;
	elem->fd_in = create_fd(-1, -1);
	elem->fd_out = create_fd(-1, -1);
	elem->fd_err = create_fd(-1, -1);
	elem->p_error = 0;
	elem->error = 0;
	elem->sep = NONE;
	if (split_cmd(count, &str, elem, heredocs) == -1)
	{
		delete_list_fd(elem->fd_in);
		delete_list_fd(elem->fd_out);
		delete_list_fd(elem->fd_err);
		free_char_tab(elem->av);
		free(elem);
		free(str);
		return (NULL);
	}
	elem->next = NULL;
	init_fd(elem);
	free(str);
	return (elem);
}

t_cmd	*add_cmd_elem(t_cmd *list, t_cmd *elem)
{
	t_cmd	*tmp;

	tmp = list;
	if (list == NULL)
		return (elem);
	while (list->next != NULL)
		list = list->next;
	list->next = elem;
	return (tmp);
}

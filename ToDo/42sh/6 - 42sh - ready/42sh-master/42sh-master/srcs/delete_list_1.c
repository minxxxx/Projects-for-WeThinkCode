/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_list_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

void	delete_list_fd(t_fd *list)
{
	t_fd *tmp;

	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
}

void	delete_list_auto(t_auto *list)
{
	t_auto *tmp;

	while (list)
	{
		tmp = list->next;
		free(list->str);
		free(list);
		list = tmp;
	}
}

void	delete_list_command(t_cmd *list)
{
	t_cmd *tmp;

	while (list)
	{
		tmp = list->next;
		free_char_tab(list->av);
		delete_list_fd(list->fd_in);
		delete_list_fd(list->fd_out);
		delete_list_fd(list->fd_err);
		free(list);
		list = tmp;
	}
}

void	delete_list_history(t_history *list)
{
	t_history *tmp;

	while (list)
	{
		tmp = list->prec;
		free(list->line);
		free(list);
		list = tmp;
	}
}

void	delete_data(t_data *data)
{
	if (data->prompt)
		free(data->prompt);
	if (data->cmd)
		free(data->cmd);
	if (data->first)
		free(data->first);
	if (data->clipboard)
		free(data->clipboard);
	if (data->cmd_tmp)
		free(data->cmd_tmp);
}

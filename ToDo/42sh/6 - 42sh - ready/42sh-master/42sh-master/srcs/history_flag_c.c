/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_flag_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

static int		free_path_and_return_one(char **path)
{
	free(*path);
	return (1);
}

int				history_flag_c(t_data *data)
{
	t_history	*tmp;
	char		*path;

	while (data->history)
	{
		tmp = data->history->prec;
		free(data->history->line);
		free(data->history);
		data->history = tmp;
	}
	path = NULL;
	get_history_path(data, &path);
	if (access(path, F_OK) == 0)
	{
		if (access(path, R_OK) == 0 && access(path, W_OK) == 0)
		{
			data->history_fd = open(path, O_RDWR | O_TRUNC, 0644);
			if (close(data->history_fd) == -1)
				free_path_and_return_one(&path);
		}
		else
			free_path_and_return_one(&path);
	}
	free(path);
	return (0);
}

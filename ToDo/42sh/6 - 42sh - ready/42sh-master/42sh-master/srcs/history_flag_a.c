/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_flag_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

static void	get_history_path_anrw_last_if(char **path, char *history_name)
{
	*path = ft_strjoinaf1(*path, "/");
	*path = ft_strjoinaf1(*path, history_name);
}

int			get_history_path_anrw(t_data *data, char **path, char *scmd)
{
	char	*history_name;

	*path = find_var_env(data, "HOME", data->env);
	if (*path[0] == '\0')
	{
		free(*path);
		return (1);
	}
	else
	{
		history_name = find_var_env(data, "HISTFILE", data->env);
		if (scmd != NULL)
		{
			*path = ft_strjoinaf1(*path, "/");
			*path = ft_strjoinaf1(*path, scmd);
		}
		else if (history_name[0] == '\0')
			*path = ft_strjoinaf1(*path, "/42sh_history");
		else
			get_history_path_anrw_last_if(path, history_name);
		free(history_name);
	}
	return (0);
}

static void	write_in_file_and_free_path(char **path, int fd)
{
	write(fd, *path, ft_strlen(*path));
	free(*path);
}

int			history_flag_a(t_data *data, char *scmd)
{
	char		*path;
	int			fd;
	t_history	*history;

	if (get_history_path_anrw(data, &path, scmd) == 1)
		return (1);
	fd = open(path, O_RDWR | O_CREAT | O_APPEND, 0600);
	free(path);
	if (fd == -1 || (history = data->history) == NULL)
		return (1);
	while (history->prec && history->prec->get_from_file == 0)
		history = history->prec;
	if (history->get_from_file == 1)
		return (1);
	while (history)
	{
		path = ft_itoa_base(history->time, 10);
		path = ft_strjoinaf1(path, ";");
		path = ft_strjoinaf1(path, history->line);
		path = ft_strjoinaf1(path, "\n");
		write_in_file_and_free_path(&path, fd);
		history = history->next;
	}
	close(fd);
	return (0);
}

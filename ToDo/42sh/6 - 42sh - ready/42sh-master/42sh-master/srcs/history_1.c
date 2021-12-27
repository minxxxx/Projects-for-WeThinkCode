/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

int				get_history_path(t_data *data, char **path)
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
		if (history_name[0] == '\0')
		{
			free(history_name);
			*path = ft_strjoinaf1(*path, "/42sh_history");
		}
		else
		{
			*path = ft_strjoinaf1(*path, "/");
			*path = ft_strjoinaf12(*path, history_name);
		}
	}
	return (0);
}

int				get_history_fd(t_data *data)
{
	char	*path;

	path = NULL;
	data->history_fd = -1;
	if (get_history_path(data, &path) == 1)
		return (1);
	if (access(path, F_OK) == -1)
		data->history_fd = open(path, O_RDWR | O_CREAT | O_TRUNC, 0600);
	else if (access(path, R_OK) == 0)
		data->history_fd = open(path, O_RDONLY);
	else
		return (1);
	free(path);
	return (0);
}

int				get_history_command_part(char *line)
{
	int		i;

	i = 0;
	while (line[i] != ';' && line[i] != '\0')
		i++;
	if (line[i] == ';')
		i++;
	return (i);
}

void			init_history(t_data *data)
{
	char		*line;

	line = NULL;
	if (get_history_fd(data) == 0 && data->history_fd == -1)
		return ;
	while (get_next_line(data->history_fd, &line) == 1)
	{
		get_history_command_part(line);
		data->history = add_history_elem(data->history,
				create_history_elem(line + get_history_command_part(line)));
		data->history->time = ft_atoi(line);
		data->history->get_from_file = 1;
		free(line);
	}
	if (close(data->history_fd) == -1)
		ft_putstr_fd("42sh: history: Failed to open/close history file\n", 2);
}

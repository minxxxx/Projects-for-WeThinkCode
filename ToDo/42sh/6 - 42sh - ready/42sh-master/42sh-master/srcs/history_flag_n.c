/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_flag_n.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

static void		history_flag_n_add_history(t_data *data, char *line)
{
	t_history	*history;
	char		*command_line;
	int			time_line;

	time_line = ft_atoi(line);
	command_line = line + get_history_command_part(line);
	history = data->history;
	while (history->prec && time_line < history->time
			&& ft_strequ(history->line, command_line) == 0)
		history = history->prec;
	if (ft_strequ(history->line, command_line) == 0)
	{
		data->history = add_history_elem(data->history,
				create_history_elem(command_line));
		data->history->time = ft_atoi(line);
	}
}

int				history_flag_n(t_data *data, char *scmd, t_cmd *cmd)
{
	char		*path;
	char		*line;

	if (get_history_path_anrw(data, &path, scmd) == 1)
		return (1);
	data->history_fd = open(path, O_RDONLY);
	free(path);
	if (data->history_fd == -1 || data->history == NULL)
		return (1);
	line = NULL;
	while (get_next_line(data->history_fd, &line) == 1)
	{
		history_flag_n_add_history(data, line);
		free(line);
	}
	if (close(data->history_fd) == -1)
	{
		putstr_builtin(cmd, "42sh: history: Failed ", 2);
		putstr_builtin(cmd, "to open/close history file\n", 2);
	}
	return (0);
}

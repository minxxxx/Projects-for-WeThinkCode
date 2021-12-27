/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_builtin_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

static void		init_flag(t_data *data)
{
	int		i;

	i = 0;
	while (i < 9)
	{
		data->history_flag[i] = 0;
		i++;
	}
}

static int		history_flag_clear(t_data *data, char **scmd, t_cmd *cmd)
{
	if (data->history_flag[0])
		return (history_flag_c(data));
	else
		return (history_flag_d(data, scmd, cmd));
}

static int		history_flag_file(t_data *data, char **scmd, t_cmd *cmd)
{
	if (data->history_flag[2])
		if (history_flag_a(data, scmd[0]) == 1)
			return (1);
	if (data->history_flag[3])
		if (history_flag_w(data, scmd[0]) == 1)
			return (1);
	if (data->history_flag[4])
		if (history_flag_r(data, scmd[0], cmd) == 1)
			return (1);
	if (data->history_flag[5])
		if (history_flag_n(data, scmd[0], cmd) == 1)
			return (1);
	return (0);
}

static int		history_flag_weird(t_data *data, char **scmd, t_cmd *cmd)
{
	if (!scmd[0])
		return (1);
	if (data->history)
	{
		delete_last_history(data);
	}
	if (data->history_flag[6])
		if (history_flag_p(scmd, cmd) == 1)
			return (1);
	if (data->history_flag[7])
		if (history_flag_s(data, scmd) == 1)
			return (1);
	return (0);
}

int				ft_history(char **scmd, t_data *data, t_cmd *cmd)
{
	int		j;

	j = 0;
	init_flag(data);
	if (get_history_flag(data, scmd, &j, cmd))
		return (1);
	if (data->history_flag[0] || data->history_flag[1])
		return (history_flag_clear(data, scmd + j, cmd));
	else if (data->history_flag[2] || data->history_flag[3]
		|| data->history_flag[4] || data->history_flag[5])
		return (history_flag_file(data, scmd + j, cmd));
	else if (data->history_flag[6] || data->history_flag[7])
		return (history_flag_weird(data, scmd + j, cmd));
	return (history_flag_none(data, scmd + j, cmd));
}

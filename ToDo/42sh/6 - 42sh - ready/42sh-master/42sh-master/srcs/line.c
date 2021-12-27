/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:15 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int		can_move_up(t_data *data)
{
	int line_prompt;

	line_prompt = data->len_prompt / data->win_x;
	if (get_actual_line(data) > line_prompt)
		return (1);
	return (0);
}

int		can_move_down(t_data *data)
{
	if (get_actual_line(data) < get_line_max(data))
		return (1);
	return (0);
}

void	insert_mode(t_data *data, char c)
{
	int	new_index;

	new_index = data->index + 1;
	data->cmd = insert_char(data->cmd, data->index, c);
	ft_putstr(data->cmd + data->index);
	data->index = (int)ft_strlen(data->cmd);
	while (data->index > new_index)
	{
		move_left(data);
	}
}

void	delete_mode(t_data *data)
{
	int	index;

	if (data->index == 0 || data->cmd[data->index - 1] == '\n' \
	|| data->mode_copy)
		return ;
	if (data->index_min_win != -1 && data->index_min_win == data->index)
	{
		exec_tcap("vb");
		return ;
	}
	move_left_without_mod(data);
	exec_tcap("cd");
	index = data->index;
	ft_putstr(data->cmd + data->index + 1);
	data->cmd = delete_char(data->cmd, data->index + 1);
	data->index = ft_strlen(data->cmd);
	while (data->index > index)
		move_left_without_mod(data);
}

int		get_actual_cursor(t_data *data)
{
	int	x;
	int	i;

	x = 0;
	i = 0;
	while (data->prompt[i] != '\0')
	{
		if (data->prompt[i] == '\n' || x == data->win_x - 1)
			x = 0;
		else
			x++;
		i++;
	}
	i = 0;
	while (data->cmd[i] != '\0' && i < data->index)
	{
		if (data->cmd[i] == '\n' || x == data->win_x - 1)
			x = 0;
		else
			x++;
		i++;
	}
	return (x);
}

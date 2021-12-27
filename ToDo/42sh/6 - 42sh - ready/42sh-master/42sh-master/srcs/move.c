/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:15 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 20:13:05 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

int		verif_move(t_data *data, int flag)
{
	if (flag == 0)
	{
		if (data->index == 0 || data->cmd[data->index - 1] == '\n')
			return (0);
		if (data->index_min_win != -1 && data->index_min_win == data->index)
		{
			exec_tcap("vb");
			return (0);
		}
	}
	else
	{
		if ((data->mode_copy && data->index + 1 == (int)ft_strlen(data->cmd)) \
		|| (data->mode_copy == 0 && data->index == (int)ft_strlen(data->cmd)))
		{
			exec_tcap("vb");
			return (0);
		}
	}
	if (data->list_auto)
	{
		delete_list_auto(data->list_auto);
		data->list_auto = NULL;
	}
	return (1);
}

void	move_index(t_data *data)
{
	exec_tcap("le");
	exec_tcap("nd");
	data->index--;
}

void	move_without_mod(t_data *data, int flag)
{
	ft_putchar(data->cmd[data->index]);
	data->index++;
	if (flag == 0)
	{
		if (get_actual_cursor(data) == 0)
			move_index(data);
		else
			move_left_without_mod(data);
	}
	else
	{
		if (get_actual_cursor(data) == 0)
		{
			ft_putchar(data->cmd[data->index]);
			data->index++;
			move_left_without_mod(data);
			move_left_without_mod(data);
		}
		else
			move_left_without_mod(data);
	}
}

void	move_left(t_data *data)
{
	if (!verif_move(data, 0))
		return ;
	if (data->mode_copy && data->index == data->index_max_copy && \
			data->index_min_copy != data->index_max_copy)
	{
		move_without_mod(data, 0);
		data->index_max_copy--;
	}
	else if (data->mode_copy && data->index == data->index_min_copy)
		data->index_min_copy--;
	move_left_without_mod(data);
	if (data->mode_copy)
	{
		vi_char(data->cmd[data->index]);
		data->index++;
		if (get_actual_cursor(data) == 0)
			move_index(data);
		else
			move_left_without_mod(data);
	}
}

void	move_right(t_data *data)
{
	if (!verif_move(data, 1))
		return ;
	if (data->list_auto)
	{
		delete_list_auto(data->list_auto);
		data->list_auto = NULL;
	}
	if (data->mode_copy && data->index == data->index_min_copy && \
			data->index_min_copy != data->index_max_copy)
	{
		move_without_mod(data, 1);
		data->index_min_copy++;
	}
	else
		data->index_max_copy++;
	move_right_without_mod(data);
	if (data->mode_copy)
	{
		vi_char(data->cmd[data->index]);
		data->index++;
		if (get_actual_cursor(data) == 0)
			move_index(data);
		else
			move_left_without_mod(data);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:15 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:20 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

void	page_down_4(t_data *data)
{
	if (get_actual_cursor(data) == 0)
	{
		exec_tcap("le");
		exec_tcap("nd");
		data->index--;
	}
	else
		move_left_without_mod(data);
}

void	page_down_3(t_data *data, int tmp)
{
	while (data->index <= tmp)
	{
		if (data->index_min_copy == data->index)
			exec_tcap("mr");
		ft_putchar(data->cmd[data->index]);
		if (data->index_max_copy == data->index)
			exec_tcap("me");
		data->index++;
	}
}

void	page_down_2(t_data *data, int *tmp, int *why)
{
	if (data->index == data->index_min_copy && \
		data->index_min_copy + data->win_x <= data->index_max_copy)
	{
		data->index_min_copy = data->index_min_copy + data->win_x;
		*why = 1;
	}
	else if (data->index == data->index_min_copy && \
		data->index_max_copy != data->index_min_copy)
	{
		*tmp = data->index_min_copy;
		data->index_min_copy = data->index_max_copy;
		data->index_max_copy = *tmp + data->win_x;
	}
	else
	{
		data->index_max_copy += data->win_x;
		if (data->index >= data->index_min_copy && \
			data->index <= data->index_max_copy)
			exec_tcap("mr");
	}
}

void	page_down_1(t_data *data)
{
	if (get_actual_cursor(data) == 0)
	{
		write(1, data->cmd + data->index, data->win_x + 1);
		data->index += data->win_x + 1;
		move_left_without_mod(data);
	}
	else
	{
		write(1, data->cmd + data->index, data->win_x);
		data->index += data->win_x;
	}
}

void	page_down(t_data *data)
{
	int	tmp;
	int why;

	why = 0;
	tmp = 0;
	if ((data->index + data->win_x < (int)ft_strlen(data->cmd)\
	|| (get_actual_cursor(data) != 0 && \
	data->index + data->win_x == (int)ft_strlen(data->cmd))) && \
	!(data->mode_copy && \
	data->index + data->win_x == (int)ft_strlen(data->cmd)))
	{
		if (data->mode_copy == 0)
			page_down_1(data);
		else
		{
			page_down_2(data, &tmp, &why);
			tmp = data->index + data->win_x;
			page_down_3(data, tmp);
			why ? exec_tcap("me") : 0;
			page_down_4(data);
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boucle_mode_copy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 19:48:48 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 19:48:49 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

static void	boucle_copy(t_data *data)
{
	int	index_origin;

	if (data->list_auto)
	{
		delete_list_auto(data->list_auto);
		data->list_auto = NULL;
	}
	if (data->mode_copy)
	{
		data->mode_copy = 0;
		index_origin = data->index;
		while (data->index > data->index_min_copy)
			move_left(data);
		while (data->index <= data->index_max_copy)
		{
			ft_putchar(data->cmd[data->index]);
			data->index++;
		}
		while (data->index > index_origin)
			move_left(data);
		if (data->clipboard)
			free(data->clipboard);
		data->clipboard = ft_strsub(data->cmd, data->index_min_copy,
			data->index_max_copy - data->index_min_copy + 1);
	}
}

static void	boucle_cut(t_data *data)
{
	if (data->list_auto)
	{
		delete_list_auto(data->list_auto);
		data->list_auto = NULL;
	}
	if (data->mode_copy)
	{
		data->mode_copy = 0;
		if (data->clipboard)
			free(data->clipboard);
		data->clipboard = ft_strsub(data->cmd, data->index_min_copy,
			data->index_max_copy - data->index_min_copy + 1);
		while (data->index <= data->index_max_copy)
			move_right_without_mod(data);
		while (data->index > data->index_min_copy)
			delete_mode(data);
	}
}

static void	boucle_paste(t_data *data)
{
	int	i;

	if (data->list_auto)
	{
		delete_list_auto(data->list_auto);
		data->list_auto = NULL;
	}
	if (!data->mode_copy && data->clipboard)
	{
		i = 0;
		while (data->clipboard[i])
		{
			insert_mode(data, data->clipboard[i]);
			i++;
		}
	}
}

int			is_boucle_mode_copy(t_data *data, char buf[11])
{
	signal(SIGINT, SIG_IGN);
	if (buf[0] == -62 && buf[1] == -75 && buf[2] == 0)
		init_or_end_mode_copy(data);
	else if (buf[0] == -61 && buf[1] == -89 && buf[2] == 0)
		boucle_copy(data);
	else if (buf[0] == -30 && buf[1] == -119 && buf[2] == -120 && buf[3] == 0)
		boucle_cut(data);
	else if (buf[0] == -30 && buf[1] == -120 && buf[2] == -102 && buf[3] == 0)
		boucle_paste(data);
	else
	{
		signal(SIGINT, sigint);
		return (0);
	}
	signal(SIGINT, sigint);
	return (1);
}

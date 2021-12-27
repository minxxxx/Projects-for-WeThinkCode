/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boucle_add_or_del_char.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

static void	boucle_add_char(t_data *data, char buf[11])
{
	if (data->list_auto)
	{
		delete_list_auto(data->list_auto);
		data->list_auto = NULL;
	}
	if (data->index == (int)data->real_len_cmd)
	{
		data->cmd = ft_strjoinaf1(data->cmd, buf);
		ft_putchar(buf[0]);
		data->index++;
	}
	else
		insert_mode(data, buf[0]);
	data->real_len_cmd++;
	data->first_search = 1;
	if (data->first)
	{
		free(data->first);
		data->first = NULL;
	}
}

static void	boucle_del_char(t_data *data)
{
	if (data->list_auto)
	{
		delete_list_auto(data->list_auto);
		data->list_auto = NULL;
	}
	if (data->index > 0)
	{
		delete_mode(data);
		data->first_search = 1;
		if (data->first)
		{
			free(data->first);
			data->first = NULL;
		}
		if (ft_strequ(data->cmd, ""))
			data->history_en_cours = NULL;
	}
}

int			is_add_or_del_char(t_data *data, char buf[11])
{
	if ((ft_isalpha(buf[0]) || (buf[0] >= 32 && buf[0] <= 64)
		|| (buf[0] >= 123 && buf[0] <= 126) || (buf[0] >= 91 && buf[0] <= 96))
		&& buf[1] == '\0' && !data->mode_copy)
		boucle_add_char(data, buf);
	else if (buf[0] == 127 && buf[1] == 0 && !data->mode_copy)
		boucle_del_char(data);
	else
		return (0);
	return (1);
}

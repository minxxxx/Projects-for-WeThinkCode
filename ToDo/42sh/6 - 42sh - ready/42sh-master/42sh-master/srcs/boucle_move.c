/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boucle_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 19:48:15 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 19:48:17 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

void		real_page_up(t_data *data)
{
	if (data->list_auto)
		delete_list_auto(data->list_auto);
	data->list_auto = NULL;
	page_up(data);
}

void		real_page_down(t_data *data)
{
	if (data->list_auto)
		delete_list_auto(data->list_auto);
	data->list_auto = NULL;
	page_down(data);
}

static void	real_previous_word(t_data *data)
{
	if (data->list_auto)
	{
		delete_list_auto(data->list_auto);
		data->list_auto = NULL;
	}
	previous_word(data);
}

static void	real_next_word(t_data *data)
{
	if (data->list_auto)
	{
		delete_list_auto(data->list_auto);
		data->list_auto = NULL;
	}
	next_word(data);
}

int			is_boucle_move(t_data *data, char *buf)
{
	signal(SIGINT, SIG_IGN);
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 68 && buf[3] == 0)
		move_left(data);
	else if (buf[0] == 27 && buf[1] == 91 && buf[2] == 67 && buf[3] == 0)
		move_right(data);
	else if (is_boucle_h_e_pu_pd(data, buf))
	{
	}
	else if (buf[0] == 27 && buf[1] == 27 && buf[2] == 91 && buf[3] == 68
		&& buf[4] == 0)
		real_previous_word(data);
	else if (buf[0] == 27 && buf[1] == 27 && buf[2] == 91 && buf[3] == 67
		&& buf[4] == 0)
		real_next_word(data);
	else
	{
		signal(SIGINT, sigint);
		return (0);
	}
	signal(SIGINT, sigint);
	return (1);
}

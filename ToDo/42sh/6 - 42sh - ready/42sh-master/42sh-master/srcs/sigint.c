/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:16 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:21 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

static void	init_d_truk(t_data *data)
{
	data->first_search = 1;
	data->history_en_cours = NULL;
	free(data->cmd);
	data->cmd = ft_strdup("");
	data->index = 0;
	data->c = 0;
	free(data->prompt);
	data->prompt = print_prompt(data->env, data);
	data->len_prompt = ft_strlen(data->prompt);
	if (data->cmd_tmp)
	{
		if (data->cmd_tmp[0])
		{
			free(data->cmd_tmp);
			data->cmd_tmp = ft_strdup("");
		}
	}
	free(data->cmd_tmp);
	data->cmd_tmp = ft_strdup("");
}

void		sigint(int sig)
{
	t_data	*data;

	(void)sig;
	data = singleton_data(NULL, 0);
	exec_tcap("me");
	while (data->index < (int)ft_strlen(data->cmd))
		move_right_without_mod(data);
	ft_putstr("\n");
	init_d_truk(data);
	data->real_len_cmd = 0;
	if (data->first)
	{
		free(data->first);
		data->first = NULL;
	}
	reinitialise_heredoc(data, 1);
	data->quote_old_index = 0;
	data->mode_copy = 0;
	data->list_auto = NULL;
	data->cmd_before_auto = NULL;
	if (data->absolute_cmd_before_auto)
		free(data->absolute_cmd_before_auto);
	data->absolute_cmd_before_auto = NULL;
	data->index_before_auto = 0;
	data->index_before_move = 0;
}

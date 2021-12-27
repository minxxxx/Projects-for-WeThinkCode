/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up_history.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:15 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:20 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

static void	move_up_history_2(t_data *data)
{
	if (!data->history_en_cours)
		data->history_en_cours = data->history;
	else if (data->history_en_cours->prec)
		data->history_en_cours = data->history_en_cours->prec;
	while (!ft_strnequ(data->history_en_cours->line, data->first,
		ft_strlen(data->first))
			&& data->history_en_cours->prec)
		data->history_en_cours = data->history_en_cours->prec;
}

static int	move_up_history_1(t_data *data)
{
	t_history *temp;

	if (!data->first && data->history_en_cours == NULL)
		data->history_en_cours = data->history;
	else if (data->first)
	{
		temp = data->history_en_cours;
		move_up_history_2(data);
		if (!ft_strnequ(data->history_en_cours->line, data->first,
			ft_strlen(data->first)))
		{
			data->history_en_cours = temp;
			return (0);
		}
	}
	else
	{
		if (data->history_en_cours->prec)
			data->history_en_cours = data->history_en_cours->prec;
		else
			return (0);
	}
	return (1);
}

void		move_up_history(t_data *data, t_env *env)
{
	if (data->c == '\0' && data->history != NULL)
	{
		if (!data->first && data->first_search)
		{
			data->first_search = 0;
			if (!ft_strequ(data->cmd, ""))
				data->first = ft_strdup(data->cmd);
		}
		if (!move_up_history_1(data))
			return ;
		exec_tcap("dl");
		exec_tcap("cr");
		free(data->prompt);
		data->prompt = print_prompt(env, data);
		data->len_prompt = ft_strlen(data->prompt);
		ft_putstr((data->history_en_cours)->line);
		if (data->cmd)
			free(data->cmd);
		data->cmd = ft_strdup((data->history_en_cours)->line);
		data->real_len_cmd = ft_strlen(data->cmd);
		data->index = ft_strlen(data->cmd);
		reinit_list_auto(data);
	}
}

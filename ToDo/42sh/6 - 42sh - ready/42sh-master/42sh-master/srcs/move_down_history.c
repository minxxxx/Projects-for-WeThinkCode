/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down_history.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:15 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

static void		move_down_history_1(t_data *data)
{
	if (data->first)
	{
		data->history_en_cours = data->history_en_cours->next;
		while (data->history_en_cours &&
				!ft_strnequ(data->history_en_cours->line,
				data->first, ft_strlen(data->first)))
			data->history_en_cours = data->history_en_cours->next;
		if (!data->history_en_cours)
			data->cmd = ft_strdup(data->first);
		else
			data->cmd = ft_strdup(data->history_en_cours->line);
	}
	else if ((data->history_en_cours)->next)
	{
		data->history_en_cours = (data->history_en_cours)->next;
		data->cmd = ft_strdup(data->history_en_cours->line);
	}
	else
	{
		data->history_en_cours = NULL;
		data->cmd = ft_strdup("");
	}
}

void			move_down_history(t_data *data, t_env *env)
{
	if (data->c == '\0')
	{
		if (data->history != NULL)
		{
			if (data->history_en_cours == NULL)
				return ;
			if (data->cmd)
				free(data->cmd);
			move_down_history_1(data);
			exec_tcap("dl");
			exec_tcap("cr");
			free(data->prompt);
			data->prompt = print_prompt(env, data);
			data->len_prompt = ft_strlen(data->prompt);
			ft_putstr(data->cmd);
			data->real_len_cmd = ft_strlen(data->cmd);
			data->index = ft_strlen(data->cmd);
			if (data->list_auto)
			{
				delete_list_auto(data->list_auto);
				data->list_auto = NULL;
			}
		}
	}
}

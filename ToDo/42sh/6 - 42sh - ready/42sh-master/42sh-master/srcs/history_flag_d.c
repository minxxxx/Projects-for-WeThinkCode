/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_flag_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

static void	history_flag_d_3(t_data *data, t_history *list)
{
	t_history	*tmp_prec;
	t_history	*tmp_next;

	tmp_prec = list->prec;
	tmp_next = list->next;
	if (tmp_prec)
	{
		tmp_prec->next = tmp_next;
		if (tmp_next == NULL)
			data->history = tmp_prec;
	}
	if (tmp_next)
	{
		tmp_next->prec = tmp_prec;
		while (tmp_next->next)
			tmp_next = tmp_next->next;
		data->history = tmp_next;
	}
	if (tmp_prec == NULL && tmp_next == NULL)
		data->history = NULL;
	free(list->line);
	free(list);
}

static int	history_flag_d_2(t_data *data, t_history *list,
		int nb, t_cmd *cmd)
{
	int		i;

	i = 1;
	while (i < nb && list != NULL)
	{
		list = list->next;
		i++;
	}
	if (list == NULL || nb == 0)
	{
		putstr_builtin(cmd, "42sh: history: history ", 2);
		putstr_builtin(cmd, "position out of range\n", 2);
		return (1);
	}
	history_flag_d_3(data, list);
	return (0);
}

static int	history_flag_d_write_error(t_cmd *cmd)
{
	putstr_builtin(cmd, "42sh: history: Invalid arg, ", 2);
	putstr_builtin(cmd, "you must specify an positive integer\n", 2);
	return (1);
}

int			history_flag_d(t_data *data, char **scmd, t_cmd *cmd)
{
	t_history	*tmp_deb;
	int			j;

	j = 0;
	while (scmd[j] != NULL)
	{
		if (!(tmp_deb = data->history))
			return (0);
		while (tmp_deb->prec)
			tmp_deb = tmp_deb->prec;
		if (ft_isdigit(scmd[j][0]))
		{
			if (history_flag_d_2(data, tmp_deb, ft_atoi(scmd[j]), cmd) == 1)
				return (1);
		}
		else
			history_flag_d_write_error(cmd);
		j++;
	}
	if (j == 0)
		history_flag_d_write_error(cmd);
	return (0);
}

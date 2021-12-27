/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_flag_none_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

static int			get_history_flag_time(t_data *data)
{
	char	*str;
	int		nb;

	str = find_var_env(data, "HISTTIMEFORMAT", data->env);
	if (str[0] == '1' && str[1] == '\0')
		nb = 1;
	else
		nb = 0;
	free(str);
	return (nb);
}

static int			get_history_flag_none_arg(char **scmd, t_cmd *cmd)
{
	if (scmd[0] == NULL)
		return (-1);
	else if (ft_isdigit(scmd[0][0]))
	{
		if (scmd[1] == NULL)
			return (ft_atoi(scmd[0]));
		else
		{
			putstr_builtin(cmd, "42sh: history: Too many arguments\n", 2);
			return (-2);
		}
	}
	putstr_builtin(cmd, "42sh: history: Numeric argument required\n", 2);
	return (-2);
}

static t_history	*history_flag_none_no_nb(t_history *list, int *i)
{
	while (list->prec)
		list = list->prec;
	*i = 1;
	return (list);
}

static t_history	*history_flag_none_with_nb(t_history *list, int *i, int arg)
{
	t_history	*tmp;

	if (arg == 0)
		list = NULL;
	else
	{
		while (list->prec && *i < arg)
		{
			(*i)++;
			list = list->prec;
		}
		*i = 1;
		tmp = list;
		while (tmp->prec)
		{
			tmp = tmp->prec;
			(*i)++;
		}
	}
	return (list);
}

int					history_flag_none(t_data *data, char **scmd, t_cmd *cmd)
{
	t_history	*tmp_deb;
	int			flag_time;
	int			i;
	int			arg;

	if ((arg = get_history_flag_none_arg(scmd, cmd)) == -2)
		return (1);
	i = 1;
	if (arg == -1)
		tmp_deb = history_flag_none_no_nb(data->history, &i);
	else
		tmp_deb = history_flag_none_with_nb(data->history, &i, arg);
	flag_time = get_history_flag_time(data);
	while (tmp_deb)
	{
		print_line_info(tmp_deb, i, flag_time, cmd);
		i++;
		tmp_deb = tmp_deb->next;
	}
	return (0);
}

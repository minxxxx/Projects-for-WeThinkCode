/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_builtin_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

static int		is_history_flag(t_data *data, char car)
{
	int		flag;

	flag = -1;
	if (car == 'c')
		flag = 0;
	else if (car == 'd')
		flag = 1;
	else if (car == 'a')
		flag = 2;
	else if (car == 'w')
		flag = 3;
	else if (car == 'r')
		flag = 4;
	else if (car == 'n')
		flag = 5;
	else if (car == 'p')
		flag = 6;
	else if (car == 's')
		flag = 7;
	if (flag > -1)
		data->history_flag[flag] = 1;
	return (flag);
}

int				get_history_flag(t_data *data, char **scmd, int *j, t_cmd *cmd)
{
	int	i;

	while (scmd[*j] != NULL && scmd[*j][0] == '-')
	{
		i = 1;
		if (scmd[*j][1] == '\0')
			return (1);
		while (scmd[*j][i] != '\0')
		{
			if (is_history_flag(data, scmd[*j][i]) > -1)
				i++;
			else
			{
				putstr_builtin(cmd, "42sh: history: usage: history [-c] ", 2);
				putstr_builtin(cmd, "[-d offset] [n] or history -awrn [fil", 2);
				putstr_builtin(cmd, "ename] or history -ps arg [arg...]\n", 2);
				return (1);
			}
		}
		(*j)++;
	}
	return (0);
}

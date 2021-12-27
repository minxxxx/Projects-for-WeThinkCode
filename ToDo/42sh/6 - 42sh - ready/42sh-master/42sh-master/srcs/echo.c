/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

static int		special_car(char c, t_cmd *cmd, int *j)
{
	if (c == 'a')
		putchar_builtin(cmd, '\a', 1);
	else if (c == 'b')
		putchar_builtin(cmd, '\b', 1);
	else if (c == 'f')
		putchar_builtin(cmd, '\f', 1);
	else if (c == 'n')
		putchar_builtin(cmd, '\n', 1);
	else if (c == 'r')
		putchar_builtin(cmd, '\r', 1);
	else if (c == 't')
		putchar_builtin(cmd, '\t', 1);
	else if (c == 'v')
		putchar_builtin(cmd, '\v', 1);
	else if (c == '\\')
		putchar_builtin(cmd, '\\', 1);
	else if (c == 'c')
		return (1);
	else
	{
		(*j)--;
		putchar_builtin(cmd, '\\', 1);
	}
	return (0);
}

static void		ft_echo_begin(char **scmd, int *i, int *flag)
{
	*i = 0;
	*flag = 0;
	while (scmd[*i] && scmd[*i][0] == '-')
	{
		if (ft_strchr(scmd[*i], 'n'))
			*flag = 1;
		(*i)++;
	}
}

static void		ft_echo_boucle_end(char **scmd, int *i, t_cmd *cmd)
{
	if (scmd[*i + 1])
		putchar_builtin(cmd, ' ', 1);
	(*i)++;
}

static int		ft_echo_end(int flag, t_cmd *cmd)
{
	if (flag == 0)
		putchar_builtin(cmd, '\n', 1);
	return (0);
}

int				ft_echo(char **scmd, t_cmd *cmd)
{
	int				flag;
	int				i;
	int				j;

	ft_echo_begin(scmd, &i, &flag);
	while (scmd[i])
	{
		j = 0;
		while (scmd[i][j])
		{
			if (scmd[i][j] == '\\')
			{
				if (special_car(scmd[i][j + 1], cmd, &j))
					return (0);
				j++;
			}
			else
				putchar_builtin(cmd, scmd[i][j], 1);
			if (scmd[i][j])
				j++;
		}
		ft_echo_boucle_end(scmd, &i, cmd);
	}
	return (ft_echo_end(flag, cmd));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 12:08:12 by sfranc            #+#    #+#             */
/*   Updated: 2017/09/21 17:53:28 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

int		ft_builtin_history(char **cmd)
{
	int len;
	int	i;

	if (!cmd[1])
	{
		if (!g_shell->history)
			ft_putendl(STR_HIST_EMPTY);
		else
		{
			len = ft_tablen(g_shell->history);
			i = 0;
			while (i < len)
			{
				ft_putnbr(i + 1);
				ft_putstr("\t");
				ft_putendl(g_shell->history[i]);
				i++;
			}
		}
	}
	else if (ft_strequ(cmd[1], "-c"))
		ft_freetab(&g_shell->history);
	return (EXIT_SUCCESS);
}

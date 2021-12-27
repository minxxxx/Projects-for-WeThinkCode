/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 18:55:25 by sfranc            #+#    #+#             */
/*   Updated: 2017/09/15 16:37:05 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

int		ft_builtin_echo(char **cmd)
{
	int i;

	i = 1;
	if (ft_strequ(cmd[i], "-n"))
		++i;
	while (cmd[i])
	{
		ft_putstr(cmd[i]);
		if (cmd[++i])
			write(1, " ", 1);
	}
	if (!ft_strequ(cmd[1], "-n"))
		write(1, "\n", 1);
	return (EXIT_SUCCESS);
}

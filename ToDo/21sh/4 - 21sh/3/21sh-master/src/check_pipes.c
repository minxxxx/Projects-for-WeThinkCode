/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 13:19:51 by fkoehler          #+#    #+#             */
/*   Updated: 2016/09/21 15:30:43 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	parse_near_pipe(t_input *cmd, int reverse)
{
	if (reverse)
	{
		if (!(cmd = cmd->prev))
			return (-1);
		while (cmd && cmd->c != ';' && cmd->c != '|' && cmd->c != '`')
		{
			if (!ft_isspace(cmd->c) && cmd->c != '>' && cmd->c != '<')
				return (0);
			cmd = cmd->prev;
		}
	}
	else
	{
		if (!(cmd = cmd->next))
			return (-1);
		while (cmd && cmd->c != ';' && cmd->c != '|' && cmd->c != '`')
		{
			if (!ft_isspace(cmd->c) && cmd->c != '>' && cmd->c != '<')
				return (0);
			cmd = cmd->next;
		}
		if (cmd)
			return (1);
	}
	return (-1);
}

int			check_pipes(t_input *cmd, int reverse)
{
	int		ret;
	t_input	*tmp;

	tmp = cmd;
	while (tmp)
	{
		if (tmp->c == '|' && ((ret = parse_near_pipe(tmp, reverse)) != 0))
			return (ret);
		tmp = tmp->next;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_flag_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:15 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

int			history_flag_p(char **scmd, t_cmd *cmd)
{
	int		j;

	j = 0;
	while (scmd[j] != NULL)
	{
		putstr_builtin(cmd, scmd[j], 1);
		putchar_builtin(cmd, '\n', 1);
		j++;
	}
	return (0);
}

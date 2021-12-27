/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_flag_none_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

void			print_line_info(t_history *list, int i, int flg, t_cmd *cmd)
{
	putnbr_builtin(cmd, i, 1);
	if (flg == 1)
	{
		putchar_builtin(cmd, ' ', 1);
		if (list->time > 0)
			putnbr_builtin(cmd, list->time, 1);
		else
			putstr_builtin(cmd, "[NO TIMESTAMP]", 1);
	}
	putchar_builtin(cmd, ' ', 1);
	putstr_builtin(cmd, list->line, 1);
	putchar_builtin(cmd, '\n', 1);
}

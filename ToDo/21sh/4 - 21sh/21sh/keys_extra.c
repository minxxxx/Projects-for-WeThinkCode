/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_extra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 01:39:42 by sasiedu           #+#    #+#             */
/*   Updated: 2016/08/07 17:18:26 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_enter_key(t_term **sh, int tmp, int i)
{
	int		len;

	len = (ft_strlen((*sh)->prt) + (*sh)->len) % tgetnum("co");
	if ((*sh)->std_usr == 0)
		ft_history_tower("reset", (*sh)->line);
	if ((*sh)->std_usr == 0)
		(*sh)->save = ft_strdup((*sh)->line);
	ft_check_quotes((*sh)->line, &(*sh), -1);
	tputs(tgetstr("cr", 0), 0, ft_shell_putchar);
	while (tmp++ <= (*sh)->nb_lines)
		tputs(tgetstr("do", 0), 0, ft_shell_putchar);
	while (i++ < len)
		tputs(tgetstr("nd", 0), 0, ft_shell_putchar);
	(*sh)->nb_lines = 0;
	(*sh)->my_cur = 0;
	(*sh)->len = 0;
	ft_strdel(&(*sh)->prt);
	if ((*sh)->std_usr == 1)
		(*sh)->prt = ft_strdup(OTH);
	else
		(*sh)->prt = ft_strdup(USER);
	tputs(tgetstr("cr", 0), 0, ft_shell_putchar);
	return (1);
}

void	ft_home_key(t_term **sh)
{
	tputs(tgetstr("rc", 0), 0, ft_shell_putchar);
	(*sh)->my_cur = 0;
	(*sh)->std_cur = ft_strlen((*sh)->prt);
	ft_reset_screen(&(*sh), (*sh)->my_cur, 0, 0);
}

void	ft_end_key(t_term **sh)
{
	(*sh)->my_cur = (*sh)->len;
	(*sh)->std_cur = (ft_strlen((*sh)->prt) + (*sh)->len) % tgetnum("co");
	ft_reset_screen(&(*sh), (*sh)->my_cur, 0, 0);
}

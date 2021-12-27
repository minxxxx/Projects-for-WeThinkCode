/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 13:49:27 by sasiedu           #+#    #+#             */
/*   Updated: 2016/08/07 12:29:14 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_add_to_line(t_term **sh)
{
	int		ret;

	ret = ft_add_char_line(&(*sh)->line, (*sh)->buf[0], \
			(*sh)->my_cur, &(*sh)->len);
	if (ret == 0)
	{
		(*sh)->my_cur += 1;
		(*sh)->std_cur += 1;
		if ((*sh)->std_cur >= tgetnum("co"))
			(*sh)->std_cur = 0;
		ft_reset_screen(&(*sh), (*sh)->my_cur, 0, 0);
	}
	else
	{
		write(1, WORD_LONG, ft_strlen(WORD_LONG));
		ft_memset((*sh)->line, 0, MAX_LEN);
		tputs((*sh)->prt, 1, ft_shell_putchar);
	}
}

void	ft_reset_screen(t_term **sh, int cur_pos, int w, int tmp)
{
	w = tgetnum("co");
	(*sh)->my_h = (ft_strlen((*sh)->prt) + cur_pos) / w;
	(*sh)->nb_lines = (ft_strlen((*sh)->prt) + (*sh)->len) / w;
	tputs(tgetstr("rc", 0), 0, ft_shell_putchar);
	tputs(tgetstr("cd", 0), 0, ft_shell_putchar);
	tputs(tgetstr("cr", 0), 0, ft_shell_putchar);
	ft_putstr((*sh)->prt);
	tputs((*sh)->line, 0, ft_shell_putchar);
	tputs(tgetstr("rc", 0), 0, ft_shell_putchar);
	tmp = (*sh)->my_h;
	while (tmp-- > 0)
		tputs(tgetstr("do", 0), 0, ft_shell_putchar);
	tputs(tgetstr("cr", 0), 0, ft_shell_putchar);
	ft_move_cursor_right((*sh)->std_cur);
}

void	ft_remove_from_line(t_term **sh)
{
	if ((*sh)->my_cur <= 0)
		return ;
	(*sh)->my_cur -= 1;
	ft_remove_char_line(&(*sh)->line, (*sh)->my_cur, &(*sh)->len);
	(*sh)->std_cur -= 1;
	if ((*sh)->std_cur < 0)
		(*sh)->std_cur = tgetnum("co") - 1;
	ft_reset_screen(&(*sh), (*sh)->my_cur, 0, 0);
}

void	ft_move_cursor_right(int tmp)
{
	while (tmp > 0)
	{
		tputs(tgetstr("nd", 0), 0, ft_shell_putchar);
		tmp--;
	}
}

void	ft_move_cursor_left(int tmp)
{
	while (tmp < 0)
	{
		tputs(tgetstr("le", 0), 0, ft_shell_putchar);
		tmp++;
	}
}

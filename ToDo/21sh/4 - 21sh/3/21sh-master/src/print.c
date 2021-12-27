/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 18:19:07 by fkoehler          #+#    #+#             */
/*   Updated: 2016/08/30 12:44:15 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			putchar(int c)
{
	t_shell	*shell;

	shell = get_struct(0);
	write(shell->fd[3], &c, 1);
	return (0);
}

static void	print_eol(t_shell *shell, char *buf, size_t p_len)
{
	t_input *tmp;
	int		i;

	i = 0;
	tmp = shell->curs_pos;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	if (((shell->input_len + p_len) % shell->col) == 0 && i--)
	{
		ft_putstr_fd(buf, shell->fd[1]);
		tputs(tgetstr("do", NULL), shell->fd[3], &putchar);
		replace_cursor(shell, 42, 1);
	}
	else
		ft_putstr_fd(buf, shell->fd[1]);
	while (--i)
		replace_cursor(shell, 1, 1);
}

void		print_input(t_shell *shell, t_input *curs_pos, size_t p_len)
{
	int		i;
	char	buf[shell->input_len + 1];
	t_input	*tmp;

	i = 0;
	if (!curs_pos->next &&
		((get_cursor_x_pos(shell->input, curs_pos, p_len) % shell->col) == 0))
	{
		ft_putchar_fd(curs_pos->c, shell->fd[1]);
		tputs(tgetstr("do", NULL), shell->fd[3], &putchar);
	}
	else if (!curs_pos->next)
		ft_putchar_fd(curs_pos->c, shell->fd[1]);
	else
	{
		tmp = curs_pos;
		ft_bzero((void *)buf, shell->input_len + 1);
		tputs(tgetstr("cd", NULL), shell->fd[3], &putchar);
		while (tmp)
		{
			buf[i++] = tmp->c;
			tmp = tmp->next;
		}
		print_eol(shell, buf, p_len);
	}
}

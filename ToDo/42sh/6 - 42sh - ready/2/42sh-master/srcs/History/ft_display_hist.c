/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_hist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 21:30:17 by jbadenho          #+#    #+#             */
/*   Updated: 2017/11/24 02:56:16 by jbadenho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"
#define UP (read_in[0] == 27 && read_in[1] == 91 && read_in[2] == 65)
#define DOWN (read_in[0] == 27 && read_in[1] == 91 && read_in[2] == 66)
#define MOVE_UP "\033[1A"

void		ft_up(t_all *a)
{
	char	*temp;
	int		n;
	int		t;

	t = ft_get_dir();
	n = 200;
	if (a->histpos > 0)
	{
		a->histpos--;
		temp = ft_strdup(a->history[a->histpos]);
		ft_putstr_fd("\r", 0);
		while (n > 0)
		{
			ft_putstr_fd(" ", 0);
			n--;
		}
		ft_putstr(MOVE_UP);
		ft_putstr_fd("\r", 0);
		ft_print_dir();
		ft_strdel(&a->c);
		a->c = ft_strdup(temp);
		ft_strdel(&temp);
		ft_putstr_fd(a->c, 0);
		a->i = (int)ft_strlen(a->c) + t;
	}
}

void		ft_down(t_all *a)
{
	char	*temp;
	int		n;
	int		t;

	t = ft_get_dir();
	n = 200;
	if (a->histpos < ((int)ft_arraylen(a->history) - 1))
	{
		a->histpos++;
		temp = ft_strdup(a->history[a->histpos]);
		ft_putstr_fd("\r", 0);
		while (n > 0)
		{
			ft_putstr_fd(" ", 0);
			n--;
		}
		ft_putstr(MOVE_UP);
		ft_putstr_fd("\r", 0);
		ft_print_dir();
		ft_strdel(&a->c);
		a->c = ft_strdup(temp);
		ft_strdel(&temp);
		ft_putstr_fd(a->c, 0);
		a->i = (int)ft_strlen(a->c) + t;
	}
}

void		ft_ud_history(char read_in[8], t_all *a)
{
	if (UP)
		ft_up(a);
	if (DOWN)
		ft_down(a);
}

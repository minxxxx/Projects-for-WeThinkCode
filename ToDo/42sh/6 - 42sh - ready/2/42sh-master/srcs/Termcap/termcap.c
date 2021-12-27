/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 21:26:50 by jbadenho          #+#    #+#             */
/*   Updated: 2017/11/24 03:47:34 by jbadenho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

#define UP (read_in[0] == 27 && read_in[1] == 91 && read_in[2] == 65)
#define DOWN (read_in[0] == 27 && read_in[1] == 91 && read_in[2] == 66)
#define LEFT (read_in[0] == 27 && read_in[1] == 91 && read_in[2] == 68)
#define RIGHT (read_in[0] == 27 && read_in[1] ==91 && read_in[2] ==67)
#define BACKSPACE (read_in[0] == 127 && read_in[1] == 0 && read_in[2] == 0)
#define DELETE (read_in[0] == 27 && read_in[1] == 91 && read_in[2] == 51)
#define TAB (read_in[0] == 9 && read_in[1] == 0 && read_in[2] == 0)
#define SPACE (read_in[0] == 32 && read_in[1] == 0 && read_in[2] == 0)
#define ENTER (read_in[0] == 10 && read_in[1] == 0 && read_in[2] == 0)
#define MR "\033[1C"
#define ML "\033[1D"
#define BS a->i--;ft_putstr_fd("\b \b", 0);a->c[(ft_strlen(a->c) - 1)] = '\0'

int			ft_r(char read_in[8], t_all *a)
{
	if (LEFT)
	{
		ft_left(a);
		return (1);
	}
	if (RIGHT)
	{
		ft_right(a);
		return (1);
	}
	if (UP || DOWN)
	{
		ft_ud_history(read_in, a);
		return (1);
	}
	if (DELETE)
		return (1);
	return (0);
}

int			ft_cursor(char read_in[8], t_all *a)
{
	if (TAB)
	{
		ft_tabbing(a);
		return (1);
	}
	if (SPACE)
		return (0);
	if ((BACKSPACE))
	{
		ft_backspace(a);
		return (1);
	}
	if (ft_r(read_in, a) == 1)
		return (1);
	else
		return (0);
}

int			keyhook(t_all *a)
{
	char	*temp;
	char	read_in[8];

	temp = NULL;
	ft_memset(read_in, 0, 8);
	read(0, read_in, 8);
	if (ENTER)
	{
		ft_strdel(&temp);
		ft_putstr_fd("\n", 0);
		return (0);
	}
	else if (ft_cursor(read_in, a) == 0)
	{
		temp = a->c;
		if (a->c[0] != '\0')
			ft_strdel(&a->c);
		a->c = ft_strjoin(temp, read_in);
		ft_putchar_fd(read_in[0], 0);
		a->i++;
		a->pos = a->i;
	}
	return (1);
}

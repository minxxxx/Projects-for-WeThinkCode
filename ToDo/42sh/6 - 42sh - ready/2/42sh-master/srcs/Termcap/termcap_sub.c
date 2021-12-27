/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap_sub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 21:16:23 by jbadenho          #+#    #+#             */
/*   Updated: 2017/11/24 03:47:41 by jbadenho         ###   ########.fr       */
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
#define LMVV ft_putstr_fd(ML, 0);s->i--
#define LMV if(s->i > 3)LMVV
#define RMVV ft_putstr_fd(MR, 0);s->i++
#define RMV if(s->i > s->pos)RMVV

int		ft_cursor_sub(char read_in[8], t_subsh *s)
{
	if (LEFT)
	{
		LMV;
		return (1);
	}
	if (RIGHT)
	{
		RMV;
		return (1);
	}
	if (UP || DOWN || TAB || DELETE)
		return (1);
	if (SPACE)
		return (0);
	if ((BACKSPACE))
	{
		if (s->i > 3)
		{
			s->i--;
			ft_putstr_fd("\b \b", 0);
			s->c[(ft_strlen(s->c) - 1)] = '\0';
		}
		return (1);
	}
	return (0);
}

int		keyhook_sub(t_subsh *s)
{
	char			*temp;
	char			read_in[8];

	temp = ft_strnew(1);
	ft_memset(read_in, 0, 8);
	read(0, read_in, 8);
	if (ENTER)
	{
		s->i = 11;
		ft_strdel(&temp);
		ft_putendl("");
		return (0);
	}
	else if (ft_cursor_sub(read_in, s) == 0)
	{
		temp = ft_strdup(s->c);
		if (s->c[0] != '\0')
			ft_strdel(&s->c);
		s->c = ft_strjoin(temp, read_in);
		ft_strdel(&temp);
		ft_putchar_fd(read_in[0], 0);
		s->i++;
		s->pos = s->i;
	}
	return (1);
}

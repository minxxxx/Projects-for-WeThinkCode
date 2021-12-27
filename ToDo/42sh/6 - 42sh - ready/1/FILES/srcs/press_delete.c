/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_delete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <dtedgui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 10:08:53 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/22 11:53:31 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh.h"

void			go_end_line_before(void)
{
	ft_puts("up");
	fmovex(g_main_line.win_col);
}

static void		delete_char(int i)
{
	int			len;

	len = ft_strlen(g_main_line.cmd);
	g_main_line.cmd = ft_strndup(g_main_line.cmd, len - 1);
	ft_puts("dm");
	if (i == 0)
		ft_puts("le");
	ft_puts("dc");
	ft_puts("ed");
}

static void		print_line_static(void)
{
	int			i;

	i = g_main_line.curs_y;
	ft_puts("sc");
	while (i > 0)
	{
		ft_puts("up");
		i--;
	}
	ft_puts("cr");
	ft_puts("cd");
	prompt(NULL, g_main_line.cmd);
	ft_puts("rc");
	ft_puts("le");
}

static void		edit_del_char(void)
{
	char		*new;
	int			pos;
	int			j;
	int			i;
	int			len;

	i = 0;
	len = ft_strlen(g_main_line.cmd);
	pos = g_main_line.curs_x - 1;
	new = ft_strnew(len + 1);
	while (i < pos)
	{
		new[i] = g_main_line.cmd[i];
		i++;
	}
	j = i + 1;
	while (j < len)
	{
		new[i] = g_main_line.cmd[j];
		i++;
		j++;
	}
	new[i] = '\0';
	free(g_main_line.cmd);
	g_main_line.cmd = ft_strdup(new);
}

void			press_delete(void)
{
	int			i;

	i = 0;
	if (g_main_line.size_x > 0 && g_main_line.curs_x > 0)
	{
		if (g_main_line.curs_x_win == 0 && (i = 1))
		{
			g_main_line.curs_y--;
			g_main_line.curs_x_win = g_main_line.win_col - 1;
		}
		else
			g_main_line.curs_x_win--;
		if (g_main_line.curs_x == g_main_line.size_x)
		{
			(i == 1) ? go_end_line_before() : 1;
			delete_char(i);
		}
		else
		{
			edit_del_char();
			print_line_static();
		}
		g_main_line.curs_x--;
		g_main_line.size_x--;
	}
}

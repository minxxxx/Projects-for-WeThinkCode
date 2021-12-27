/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_letter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <dtedgui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 10:09:04 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/22 11:53:32 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh.h"

void			go_start_next_line(void)
{
	ft_puts("do");
	ft_puts("cr");
	g_main_line.curs_y++;
}

void			print_line(int edit)
{
	int			i;

	i = g_main_line.curs_y;
	if (edit == 1)
		ft_puts("sc");
	while (i > 0)
	{
		ft_puts("up");
		i--;
	}
	ft_puts("cr");
	ft_puts("cd");
	prompt(NULL, g_main_line.cmd);
	if (edit == 1)
	{
		ft_puts("rc");
		ft_puts("nd");
	}
}

void			edit_add_char(char key)
{
	char		*new;
	int			pos;
	int			j;
	int			i;
	int			len;

	i = 0;
	len = ft_strlen(g_main_line.cmd);
	pos = g_main_line.curs_x;
	new = ft_strnew(len + 1);
	while (i < pos)
		((new[i] = g_main_line.cmd[i])) ? i++ : 1;
	new[i] = key;
	j = i + 1;
	while (i < len)
	{
		new[j] = g_main_line.cmd[i];
		i++;
		j++;
	}
	new[j] = '\0';
	free(g_main_line.cmd);
	g_main_line.cmd = ft_strdup(new);
}

void			print_letter(char *key)
{
	int			i;

	i = 0;
	if (g_main_line.curs_x_win == g_main_line.win_col - 1 && (i = 1))
	{
		g_main_line.curs_x_win = 0;
		g_main_line.size_y++;
	}
	else
		g_main_line.curs_x_win++;
	if (g_main_line.curs_x == g_main_line.size_x)
	{
		ft_putstr(key);
		g_main_line.cmd = ft_strjoin(g_main_line.cmd, key);
		(i == 1) ? go_start_next_line() : 1;
	}
	else
	{
		edit_add_char(key[0]);
		print_line(1);
		(i == 1) ? go_start_next_line() : 1;
	}
	g_main_line.curs_x++;
	g_main_line.size_x++;
}

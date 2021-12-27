/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <dtedgui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 11:01:45 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/26 16:18:14 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh.h"

char				*get_current_word(void)
{
	int				start;
	int				end;
	char			*word;

	word = ft_strnew(1);
	start = g_main_line.curs_x;
	while (ft_isalpha(g_main_line.cmd[start - 1]))
		start--;
	end = start;
	while (ft_isalpha(g_main_line.cmd[end]))
		end++;
	word = ft_strsub(g_main_line.cmd, start, end - start);
	if (ft_strlen(word) > 0)
		return (word);
	else
		return (NULL);
}

void				complete_word(char *word, size_t start)
{
	char	*end;
	int		i;

	end = ft_strsub(word, start, ft_strlen(word) - start);
	i = g_main_line.curs_x;
	while (i < g_main_line.size_x && ft_isalpha(g_main_line.cmd[i]))
	{
		move_front();
		i++;
	}
	g_main_line.cmd = ft_str_insert(g_main_line.cmd, end, g_main_line.curs_x);
	g_main_line.curs_x += ft_strlen(end);
	g_main_line.size_x += ft_strlen(end);
	g_main_line.curs_x_win = (g_main_line.size_x + g_main_line.prompt)
							% g_main_line.win_col;
	g_main_line.curs_y = (g_main_line.size_x + g_main_line.prompt)
						/ g_main_line.win_col;
	print_line(0);
}

void				autocomplete(t_cmd_path *cmds)
{
	int				count;
	char			*word;
	char			*res;

	count = 0;
	if ((word = get_current_word()) == NULL)
		return ;
	while (cmds)
	{
		if (!ft_strncmp(cmds->name, word, ft_strlen(word)))
		{
			res = ft_strdup(cmds->name);
			count++;
		}
		cmds = cmds->next;
	}
	if (count == 1)
		complete_word(res, ft_strlen(word));
}

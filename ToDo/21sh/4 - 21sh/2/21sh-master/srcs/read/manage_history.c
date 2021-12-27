/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 14:21:40 by sfranc            #+#    #+#             */
/*   Updated: 2017/09/21 17:47:01 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

void		ft_history_back(t_input *input)
{
	if (!g_shell->history)
		tputs(tgetstr("bl", NULL), 1, &ft_intputchar);
	else
	{
		if (g_shell->histo_index > 0)
		{
			ft_clear_screen(input);
			ft_insertchar(g_shell->history[g_shell->histo_index - 1], input);
			g_shell->histo_index--;
		}
		else
			tputs(tgetstr("bl", NULL), 1, &ft_intputchar);
	}
}

void		ft_history_forth(t_input *input)
{
	if (!g_shell->history)
		tputs(tgetstr("bl", NULL), 1, &ft_intputchar);
	else
	{
		if (g_shell->histo_index < ft_tablen(g_shell->history) - 1)
		{
			ft_clear_screen(input);
			g_shell->histo_index++;
			ft_insertchar(g_shell->history[g_shell->histo_index], input);
		}
		else
			tputs(tgetstr("bl", NULL), 1, &ft_intputchar);
	}
}

static char	*ft_search_in_history(char *line)
{
	int		len;

	if (!line || !*line)
		return (NULL);
	if (!g_shell->history)
		return (NULL);
	len = ft_tablen(g_shell->history);
	while (len--)
	{
		if (ft_strstr(g_shell->history[len], line))
			return (ft_strdup(g_shell->history[len]));
	}
	return (NULL);
}

static void	ft_close_termcaps(void)
{
	g_shell->ret_cmd = EXIT_SUCCESS;
	free(g_shell->input.line);
	free(g_shell->input.tmp);
	ft_canonic_term();
	write(1, "\n", 1);
}

void		ft_history_search(t_input *input)
{
	char	*line;
	char	*little;
	char	*tmp;

	ft_clear_screen(input);
	ft_close_termcaps();
	ft_read_line(&line, write(1, HISTO_PROMPT, ft_strlen(HISTO_PROMPT)), 3);
	ft_raw_term();
	tmp = NULL;
	if (!g_shell->sigint)
	{
		little = ft_strsub(line, 0, ft_strlen(line) - 1);
		if (!(tmp = ft_search_in_history(little)))
		{
			ft_putendl("No match found...");
			tmp = ft_strdup(little);
		}
		free(little);
	}
	ft_init_input_struct(&g_shell->input, ft_display_prompt());
	if (tmp)
		ft_insertchar(tmp, input);
	free(tmp);
	free(line);
}

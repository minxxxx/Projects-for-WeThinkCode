/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_moves_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 17:07:36 by fkoehler          #+#    #+#             */
/*   Updated: 2016/09/19 17:19:32 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	list_and_cursor_next(t_shell *shell)
{
	if (!shell->curs_pos->next)
		return (-1);
	shell->curs_pos = shell->curs_pos->next;
	replace_cursor(shell, 0, 0);
	return (0);
}

int			move_left_word(t_shell *shell)
{
	if (!shell->input || !shell->curs_pos)
		return (-1);
	while (shell->curs_pos && shell->curs_pos->c == ' ')
	{
		replace_cursor(shell, 0, 1);
		shell->curs_pos = shell->curs_pos->prev;
	}
	while (shell->curs_pos && shell->curs_pos->c != ' ')
	{
		replace_cursor(shell, 0, 1);
		shell->curs_pos = shell->curs_pos->prev;
	}
	return (0);
}

int			move_right_word(t_shell *shell)
{
	int	i;

	i = 0;
	if (!shell->input || (shell->curs_pos && !shell->curs_pos->next))
		return (-1);
	if (!shell->curs_pos)
	{
		shell->curs_pos = shell->input;
		replace_cursor(shell, 0, 0);
	}
	while (shell->curs_pos->next &&
		shell->curs_pos->c == ' ' && shell->curs_pos->next->c == ' ')
	{
		list_and_cursor_next(shell);
		i++;
	}
	if (i == 0 && (list_and_cursor_next(shell) != -1))
	{
		while (shell->curs_pos->next && shell->curs_pos->c != ' ')
			list_and_cursor_next(shell);
		while (shell->curs_pos->next && shell->curs_pos->next->c == ' ')
			list_and_cursor_next(shell);
	}
	return (0);
}

int			move_line_up(t_shell *shell)
{
	size_t	i;

	i = shell->col;
	while (shell->curs_pos && i--)
		move_left(shell);
	return (0);
}

int			move_line_down(t_shell *shell)
{
	size_t	i;

	i = shell->col;
	if (!shell->input)
		return (-1);
	if (!shell->curs_pos)
	{
		move_right(shell);
		i--;
	}
	while (shell->curs_pos->next && i--)
		move_right(shell);
	return (0);
}

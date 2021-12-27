/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_cut_copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 20:29:43 by fkoehler          #+#    #+#             */
/*   Updated: 2016/08/29 15:47:19 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		copy_eol(t_shell *shell)
{
	t_input *tmp;

	if (shell->buffer)
		free_input_list(&(shell->buffer), NULL);
	if (!shell->input || (shell->curs_pos && !shell->curs_pos->next))
		return (-1);
	if (!(tmp = shell->curs_pos))
		copy_all(shell);
	else
	{
		tmp = tmp->next;
		while (tmp)
		{
			store_buffer(&(shell->buffer), tmp->c);
			tmp = tmp->next;
		}
	}
	return (0);
}

int		copy_all(t_shell *shell)
{
	t_input *tmp;

	if (shell->buffer)
		free_input_list(&(shell->buffer), NULL);
	if (!(tmp = shell->input))
		return (-1);
	while (tmp)
	{
		store_buffer(&(shell->buffer), tmp->c);
		tmp = tmp->next;
	}
	return (0);
}

int		cut_eol(t_shell *shell)
{
	if (copy_eol(shell) == -1)
		return (-1);
	tputs(tgetstr("cd", NULL), shell->fd[3], &putchar);
	if (!shell->curs_pos)
		free_input_list(&(shell->input), &(shell->input_len));
	else
		free_input_list(&(shell->curs_pos->next), &(shell->input_len));
	return (0);
}

int		cut_all(t_shell *shell)
{
	if (copy_all(shell) == -1)
		return (-1);
	move_line_start(shell);
	tputs(tgetstr("cd", NULL), shell->fd[3], &putchar);
	free_input_list(&(shell->input), &(shell->input_len));
	return (0);
}

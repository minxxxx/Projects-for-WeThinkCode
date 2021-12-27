/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 18:54:12 by fkoehler          #+#    #+#             */
/*   Updated: 2016/09/21 19:09:44 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	store_input_buf(t_input *input, size_t len, char **buffer)
{
	int		i;
	t_input	*tmp;

	i = 0;
	tmp = input;
	if (*buffer)
		free(*buffer);
	if (!(*buffer = ft_strnew(len)))
		quit_error(9);
	while (tmp)
	{
		(*buffer)[i++] = tmp->c;
		tmp = tmp->next;
	}
}

static void	print_input_buf(t_shell *shell)
{
	int	i;

	i = 0;
	shell->hist_end = 1;
	if (shell->input_buf)
	{
		while (shell->input_buf && shell->input_buf[i])
		{
			store_input(shell, shell->input_buf[i++]);
			print_input(shell, shell->curs_pos, shell->p_len);
		}
		free(shell->input_buf);
		shell->input_buf = NULL;
	}
}

int			history_prev(t_shell *shell)
{
	t_input		*tmp;

	if ((!shell->hist) || (!shell->hist->prev && !shell->hist_end))
		return (-1);
	if (shell->hist_end && shell->input)
		store_input_buf(shell->input, shell->input_len, &(shell->input_buf));
	if (shell->hist_end)
		shell->hist_end = 0;
	else
		shell->hist = shell->hist->prev;
	if (shell->input)
		clear_input(shell);
	tmp = shell->hist->input;
	while (tmp)
	{
		store_input(shell, tmp->c);
		print_input(shell, shell->curs_pos, shell->p_len);
		tmp = tmp->next;
	}
	return (0);
}

int			history_next(t_shell *shell)
{
	t_input	*tmp;

	if ((!shell->hist) || (!shell->hist->next && shell->hist_end))
		return (-1);
	if (shell->input)
		clear_input(shell);
	if (!(shell->hist->next))
		print_input_buf(shell);
	else if (shell->hist->next)
	{
		shell->hist = shell->hist->next;
		tmp = shell->hist->input;
		while (tmp)
		{
			store_input(shell, tmp->c);
			print_input(shell, shell->curs_pos, shell->p_len);
			tmp = tmp->next;
		}
	}
	return (0);
}

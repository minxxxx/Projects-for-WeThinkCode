/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 20:57:31 by fkoehler          #+#    #+#             */
/*   Updated: 2016/08/19 10:13:45 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	store_buffer(t_input **buf, char c)
{
	t_input	*new;
	t_input	*tmp;

	if (!(new = (t_input *)malloc(sizeof(*new))))
		quit_error(9);
	new->c = c;
	new->next = NULL;
	if (!(*buf))
	{
		new->prev = NULL;
		*buf = new;
	}
	else
	{
		tmp = *buf;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}

int		paste_buffer(t_shell *shell)
{
	t_input *tmp;

	if (!shell->buffer)
		return (-1);
	tmp = shell->buffer;
	while (tmp)
	{
		store_input(shell, tmp->c);
		print_input(shell, shell->curs_pos, shell->p_len);
		tmp = tmp->next;
	}
	return (0);
}

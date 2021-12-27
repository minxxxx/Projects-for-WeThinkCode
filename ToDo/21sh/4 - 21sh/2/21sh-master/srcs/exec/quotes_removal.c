/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_removal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 17:11:04 by sfranc            #+#    #+#             */
/*   Updated: 2017/09/20 17:07:19 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

void	ft_remove_quoting(t_token *token)
{
	t_token *tmp;
	char	*new;

	tmp = token;
	while (tmp)
	{
		if (tmp->token_type == WORD)
		{
			new = ft_remove_quotes(tmp->str);
			free(tmp->str);
			tmp->str = new;
		}
		if (tmp->operator_type == DLESS)
		{
			ft_heredoc_expand_remove_quoting(tmp);
		}
		tmp = tmp->next;
	}
}

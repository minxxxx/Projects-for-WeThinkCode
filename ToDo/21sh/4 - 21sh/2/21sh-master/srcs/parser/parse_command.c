/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 17:52:50 by sfranc            #+#    #+#             */
/*   Updated: 2017/10/04 15:52:36 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

static int		ft_incomplete_list(t_lexer *lexer)
{
	if (lexer->last->token_type == NEWLINE && lexer->nbr_token > 1\
			&& lexer->last->prev->operator_type == PIPE)
	{
		return (PIPE);
	}
	if (lexer->last->token_type == NEWLINE && lexer->nbr_token > 1\
			&& lexer->last->prev->operator_type == AND_IF)
	{
		return (AND_IF);
	}
	if (lexer->last->token_type == NEWLINE && lexer->nbr_token > 1\
			&& lexer->last->prev->operator_type == OR_IF)
	{
		return (OR_IF);
	}
	return (0);
}

static t_token	*ft_is_heredoc(t_lexer *lexer)
{
	t_token	*tmp;

	tmp = lexer->first;
	while (tmp)
	{
		if (tmp->operator_type == DLESS && tmp->heredoc == NULL)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int				ft_parser(t_lexer *lexer)
{
	int		list_type;
	t_token	*dless;
	int		ret;

	if (!lexer || !lexer->nbr_token || g_shell->sigint)
		return (EXIT_FAILURE);
	if ((ret = ft_syntax_error(lexer)))
		return (PARSER_ERROR);
	if (lexer->last->quoting)
		ret = ft_read_again_quoting(lexer);
	else if ((dless = ft_is_heredoc(lexer)))
		ret = ft_read_again_heredoc(lexer, dless);
	else if ((list_type = ft_incomplete_list(lexer)))
		ret = ft_read_again_list(lexer, list_type);
	return (ret);
}

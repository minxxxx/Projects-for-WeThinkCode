/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 13:53:15 by sfranc            #+#    #+#             */
/*   Updated: 2017/09/15 16:29:39 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

static int	ft_redirect(t_token *redir)
{
	if (redir->prev && redir->prev->token_type == IO_NUMBER)
	{
		return (ft_make_dup2(redir->next->str, redir->fd,\
					ft_atoi(redir->prev->str)));
	}
	else if (redir->operator_type == LESS)
		return (ft_make_dup2(redir->next->str, redir->fd, STDIN_FILENO));
	else
		return (ft_make_dup2(redir->next->str, redir->fd, STDOUT_FILENO));
}

static int	ft_handle_redir(t_token *tmp)
{
	if (tmp->operator_type == LESS_AND
			|| tmp->operator_type == GREAT_AND)
	{
		if (ft_agreg_files(tmp) == REDIR_ERROR)
			return (REDIR_ERROR);
	}
	else if (tmp->operator_type == DLESS)
	{
		if (ft_heredoc_pipe(tmp) == REDIR_ERROR)
			return (REDIR_ERROR);
	}
	else
	{
		if (ft_open_file(tmp) == REDIR_ERROR)
			return (REDIR_ERROR);
		if (ft_redirect(tmp) == REDIR_ERROR)
			return (REDIR_ERROR);
	}
	return (EXIT_SUCCESS);
}

int			ft_init_redirection(t_ast *ast)
{
	t_token	*tmp;

	tmp = ast->token;
	while (tmp)
	{
		if (tmp->token_type == REDIRECT)
		{
			if (ft_handle_redir(tmp) == REDIR_ERROR)
				return (REDIR_ERROR);
			tmp = tmp->next->next;
		}
		else
			tmp = tmp->next;
	}
	return (REDIR_OK);
}

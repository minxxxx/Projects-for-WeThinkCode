/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redir_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

static void	print_error_redir(char *str, char *quote)
{
	ft_putstr_fd(str, 2);
	ft_putendl_fd(quote, 2);
}

int			print_error_fd_file(t_redir redir, t_cmd *cmd)
{
	if ((redir.redir_type == 0 || redir.redir_type == 1)
		&& access(redir.quote, F_OK) == -1)
		print_error_redir("42sh: permission denied: ", redir.quote);
	else if (access(redir.quote, F_OK) == -1)
		print_error_redir("42sh: no such file or directory: ", redir.quote);
	else if ((redir.redir_type == 0 || redir.redir_type == 1)
		&& access(redir.quote, W_OK) == -1)
		print_error_redir("42sh: permission denied: ", redir.quote);
	else if (redir.redir_type == 1 && access(redir.quote, R_OK) == -1)
		print_error_redir("42sh: permission denied: ", redir.quote);
	else
		print_error_redir("42sh: Error while opening the file: ", redir.quote);
	cmd->error = 1;
	free(redir.quote);
	return (0);
}

int			error_open_file(t_redir *redir, t_cmd *cmd)
{
	ft_putstr_fd("42sh: error while opening file: ", 2);
	ft_putstr_fd(redir->quote, 2);
	ft_putstr_fd("\n", 2);
	cmd->error = 1;
	free(redir->quote);
	return (1);
}

int			error_handling_heredoc(t_redir *redir, t_cmd *cmd)
{
	ft_putstr_fd("42sh: error while handling heredoc. \n", 2);
	cmd->error = 1;
	free(redir->quote);
	return (1);
}

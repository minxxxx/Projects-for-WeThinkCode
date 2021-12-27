/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

static int	invalid_fd_or_empty_quote(char *quote, size_t *i, size_t tmp)
{
	if (ft_strequ(quote, ""))
	{
		*i = tmp;
		free(quote);
		return (0);
	}
	free(quote);
	*i = tmp;
	return (1);
}

static int	init_fd_file(t_redir *redir, t_cmd *cmd, t_hc **heredocs)
{
	int			pipe_tab[2];

	if (redir->redir_type == 0)
		redir->fd_file = open(redir->quote, O_WRONLY | O_CREAT
			| O_TRUNC, 0644);
	else if (redir->redir_type == 1)
		redir->fd_file = open(redir->quote, O_WRONLY | O_CREAT
			| O_APPEND, 0644);
	else if (redir->redir_type == 2)
	{
		if ((redir->fd_file = open(redir->quote, O_RDONLY)) < 0)
			return (error_open_file(redir, cmd));
	}
	else if (redir->redir_type == 3)
	{
		if (pipe(pipe_tab) == -1)
			return (error_handling_heredoc(redir, cmd));
		write(pipe_tab[1], (*heredocs)->content,
			ft_strlen((*heredocs)->content));
		close(pipe_tab[1]);
		redir->fd_file = pipe_tab[0];
		*heredocs = (*heredocs)->next;
	}
	return (0);
}

static void	handle_redir_add_fd(t_redir redir, t_cmd *cmd)
{
	if (redir.fd == 0)
		cmd->fd_in = add_fd_elem(cmd->fd_in, create_fd(redir.fd_file,
			redir.fd_file));
	else if (redir.fd == 1)
		cmd->fd_out = add_fd_elem(cmd->fd_out, create_fd(redir.fd_file,
			redir.fd_file));
	else if (redir.fd == 2)
		cmd->fd_err = add_fd_elem(cmd->fd_err, create_fd(redir.fd_file,
			redir.fd_file));
}

static int	do_handle_redir(char **str, size_t tmp, t_redir redir, size_t *i)
{
	while (ft_isspace2((*str)[tmp]))
		tmp++;
	if (is_empty(*str, &tmp))
	{
		redir.cmd->p_error = 1;
		return (0);
	}
	redir.quote = skip_quotes(str, &tmp, redir.cmd);
	if (!redir.quote)
		redir.quote = ft_strdup("");
	if (redir.fd > 2 || ft_strequ(redir.quote, ""))
		return (invalid_fd_or_empty_quote(redir.quote, i, tmp));
	if (init_fd_file(&redir, redir.cmd, redir.heredocs))
		return (1);
	if (redir.fd_file == -1)
		return (print_error_fd_file(redir, redir.cmd));
	handle_redir_add_fd(redir, redir.cmd);
	*i = tmp;
	free(redir.quote);
	return (1);
}

int			handle_redir(size_t *i, char **str, t_cmd *cmd, t_hc **heredocs)
{
	size_t		tmp;
	t_redir		redir;

	redir.fd_file = -1;
	tmp = *i;
	redir.fd = ((*str)[tmp] == '>' ? 1 : 0);
	if (!find_if_is_redir(*str, &tmp, &redir.fd, &redir.redir_type))
		return (0);
	if (tmp != *i)
	{
		redir.cmd = cmd;
		redir.heredocs = heredocs;
		return (do_handle_redir(str, tmp, redir, i));
	}
	return (0);
}

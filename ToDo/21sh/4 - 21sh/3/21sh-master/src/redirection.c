/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 14:46:45 by fkoehler          #+#    #+#             */
/*   Updated: 2016/09/25 18:05:04 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	open_file(char *file, int redir_type, int *fd)
{
	int		file_fd;

	file_fd = -1;
	if (redir_type == REDIR)
		file_fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (redir_type == DREDIR)
		file_fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (redir_type == BREDIR)
		file_fd = open(file, O_RDONLY);
	else if (redir_type == HEREDOC)
	{
		signal(SIGINT, &sig_handler_heredoc);
		signal(SIGTSTP, &sig_handler_heredoc);
		file_fd = fill_heredoc(file, fd);
		signal(SIGINT, &sig_handler1);
		signal(SIGTSTP, &sig_handler);
	}
	return (file_fd);
}

static int	parse_redir(t_redir *redir, int *fd, int fd1, int i)
{
	int		fd2;
	char	*file;

	fd2 = 0;
	if ((fd[fd1] != fd1) && (fd[fd1] != -1))
		close(fd[fd1]);
	if (redir->s[++i] == '&' && redir->s[i + 1] == '-')
		fd[fd1] = -1;
	else if (redir->s[i] == '&' && redir->type != DREDIR &&
			redir->type != HEREDOC && ft_isdigit(redir->s[i + 1]))
		fd[fd1] = (redir->s[i + 1] - 48);
	else
	{
		redir->s[i] == '&' ? i++ : (0);
		file = ft_strtrim(redir->s + i);
		fd2 = open_file(file, redir->type, fd);
		free(file);
		if (fd2 != -1)
			fd[fd1] = fd2;
		return (fd2 == -1) ? exec_error(8, "") : 0;
	}
	return (0);
}

int			handle_redirs(t_shell *shell, t_btree *link, char **cmd)
{
	int		i;
	int		fd1;
	t_redir	*redir;

	redir = link->redir;
	while (redir)
	{
		if (!ft_isdigit(redir->s[0]))
			fd1 = ((redir->type == BREDIR) || (redir->type == HEREDOC)) ? 0 : 1;
		else
			fd1 = ft_atoi(redir->s);
		i = (redir->type == REDIR || redir->type == DREDIR) ?
		ft_strrchr_index(redir->s, '>') : ft_strrchr_index(redir->s, '<');
		if (parse_redir(redir, shell->fd, fd1, i) == -1)
		{
			close_and_reset_fd(shell->fd);
			return (-1);
		}
		redir = redir->next;
	}
	return (redir_fork(cmd, shell));
}

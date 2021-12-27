/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_dup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 16:25:29 by sfranc            #+#    #+#             */
/*   Updated: 2017/09/15 16:30:11 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

int		ft_make_dup2(char *dest_name, int fd_dest, int fd_src)
{
	errno = 0;
	if ((dup2(fd_dest, fd_src)) != -1)
		return (REDIR_OK);
	else
	{
		if (errno == EBADF)
			ft_put_cmd_error(dest_name, STR_BAD_FD);
		else
			ft_put_cmd_error(dest_name, STR_DUP_ERROR);
		return (REDIR_ERROR);
	}
}

int		ft_open_error(int fd, int err, char *file_name)
{
	if (fd != -1)
		return (REDIR_OK);
	else
	{
		if (err == EACCES)
			ft_put_cmd_error(file_name, STR_PERM_DENIED);
		else if (err == EISDIR)
			ft_put_cmd_error(file_name, STR_IS_DIR);
		else if (err == ENOENT)
			ft_put_cmd_error(file_name, STR_NO_FILE);
		else
			ft_put_cmd_error(file_name, STR_OPEN_ERROR);
		return (REDIR_ERROR);
	}
}

int		ft_open_file(t_token *redir)
{
	errno = 0;
	if (redir->operator_type == DGREAT)
	{
		if ((redir->fd = open(redir->next->str, O_WRONLY | O_CREAT | O_APPEND,\
						S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
			return (ft_open_error(redir->fd, errno, redir->next->str));
	}
	else if (redir->operator_type == LESS)
	{
		if ((redir->fd = open(redir->next->str, O_RDONLY)) == -1)
			return (ft_open_error(redir->fd, errno, redir->next->str));
	}
	else
	{
		if ((redir->fd = open(redir->next->str, O_WRONLY | O_CREAT | O_TRUNC,\
						S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
			return (ft_open_error(redir->fd, errno, redir->next->str));
	}
	return (REDIR_OK);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

void	putstr_builtin(t_cmd *cmd, char *str, int fd)
{
	t_fd *fd_ptr;

	if (fd == 1)
		fd_ptr = cmd->fd_out;
	else if (fd == 2)
		fd_ptr = cmd->fd_err;
	else
		return ;
	if (!fd_ptr)
		return ;
	ft_putstr_fd(str, fd_ptr->fd);
}

void	putchar_builtin(t_cmd *cmd, char car, int fd)
{
	t_fd *fd_ptr;

	if (fd == 1)
		fd_ptr = cmd->fd_out;
	else if (fd == 2)
		fd_ptr = cmd->fd_err;
	else
		return ;
	if (!fd_ptr)
		return ;
	ft_putchar_fd(car, fd_ptr->fd);
}

void	putnbr_builtin(t_cmd *cmd, int nb, int fd)
{
	t_fd *fd_ptr;

	if (fd == 1)
		fd_ptr = cmd->fd_out;
	else if (fd == 2)
		fd_ptr = cmd->fd_err;
	else
		return ;
	if (!fd_ptr)
		return ;
	ft_putnbr_fd(nb, fd_ptr->fd);
}

void	putendl_builtin(t_cmd *cmd, char *str, int fd)
{
	t_fd *fd_ptr;

	if (fd == 1)
		fd_ptr = cmd->fd_out;
	else if (fd == 2)
		fd_ptr = cmd->fd_err;
	else
		return ;
	if (!fd_ptr)
		return ;
	ft_putstr_fd(str, fd_ptr->fd);
	ft_putchar_fd('\n', fd_ptr->fd);
}

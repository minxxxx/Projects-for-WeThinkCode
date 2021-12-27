/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 11:25:45 by jtranchi          #+#    #+#             */
/*   Updated: 2018/05/24 11:25:47 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ftp.h"

int		exec_mkdir(char **tabl, int fd)
{
	if (!tabl[1])
		return (write_error("mkdir", "missing argument", fd));
	if (mkdir(tabl[1], 0777) == -1)
		return (write_error("mkdir", "error", fd));
	write_success("mkdir", fd);
	return (0);
}

int		exec_rmdir(char **tabl, int fd)
{
	if (!tabl[1])
		return (write_error("rmdir", "missing argument", fd));
	if (rmdir(tabl[1]) == -1)
		return (write_error("rmdir", "error", fd));
	write_success("rmdir", fd);
	return (0);
}

int		exec_unlink(char **tabl, int fd)
{
	if (!tabl[1])
		return (write_error("unlink", "missing argument", fd));
	if (unlink(tabl[1]) == -1)
		return (write_error("unlink", "error", fd));
	write_success("unlink", fd);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 13:04:29 by jcamhi            #+#    #+#             */
/*   Updated: 2017/08/31 13:04:30 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

void	func_size(t_data *data)
{
	t_command	cmd;
	int			fd;
	struct stat	stats;

	if (!data->logged_in)
		return (setret(data, 530, ERROR_NOT_LOGGED, 1));
	cmd = *(data->cmd);
	if (!cmd.argument)
		return (setret(data, 550, " Could not get file size.", 1));
	if ((fd = open_wrapper(data, cmd.argument, O_RDONLY, 0)) == -1)
		return (setret(data, 550, " Could not get file size.", 1));
	if (fstat(fd, &stats) == -1)
	{
		close(fd);
		return (setret(data, 550, " Could not get file size.", 1));
	}
	close(fd);
	data->free_commentaire = 1;
	return (setret(data, 213,
		ft_strjoinaf2(" ", ft_itoa_base(stats.st_size, 10)), -2));
}

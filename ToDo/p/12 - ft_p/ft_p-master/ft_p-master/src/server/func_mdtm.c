/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_mdtm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 13:04:20 by jcamhi            #+#    #+#             */
/*   Updated: 2017/08/31 13:04:21 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

void	func_mdtm(t_data *data)
{
	t_command	cmd;
	int			fd;
	struct stat	stats;

	if (!data->logged_in)
		return (setret(data, 530, " Please login with USER and PASS", 1));
	cmd = *(data->cmd);
	if (!cmd.argument)
		return (setret(data, 550, " Could not get file modification time.", 1));
	if ((fd = open_wrapper(data, cmd.argument, O_RDONLY, 0)) == -1)
		return (setret(data, 550, " Could not get file modification time.", 1));
	if (fstat(fd, &stats) == -1)
	{
		close(fd);
		return (setret(data, 550, " Could not get file modification time.", 1));
	}
	close(fd);
	data->return_code = 213;
	data->commentaire = ft_strjoinaf2(" ", ft_itoa_base_ull(
		(unsigned long long)stats.st_mtimespec.tv_sec * 1000, 10));
	data->free_commentaire = 1;
	return ;
}

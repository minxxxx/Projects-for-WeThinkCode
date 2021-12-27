/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_retr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 13:04:27 by jcamhi            #+#    #+#             */
/*   Updated: 2017/08/31 13:04:29 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

static off_t	get_size(int fd, t_data *data)
{
	struct stat	stats;

	if (fstat(fd, &stats) == -1)
	{
		data->return_code = 550;
		data->commentaire = " Could not get file size.";
		data->error = 1;
		close(fd);
		return (0);
	}
	return (stats.st_size);
}

static void		fml(int *cs, char *ptr, char **oldptr)
{
	write(*cs, *oldptr, ptr - *oldptr);
	write(*cs, "\r\n", 2);
	*oldptr = ptr + 1;
}

static void		do_read_write(t_data *data, int fd, int cs)
{
	int		r;
	char	str[BUFF_SIZE_2];
	char	*ptr;
	char	*oldptr;

	while ((r = read(fd, str, BUFF_SIZE_2 - 1)) > 0)
	{
		str[r] = '\0';
		if (data->type == TYPE_BINARY)
			write(cs, str, r);
		else if (data->type == TYPE_ASCII)
		{
			ptr = str;
			oldptr = str;
			while (ptr && *oldptr)
			{
				if ((ptr = ft_strchr(oldptr, '\n')))
					fml(&cs, ptr, &oldptr);
				else if (oldptr)
					write(cs, oldptr, ft_strlen(oldptr));
			}
		}
	}
}

static int		put_open_binary(t_data *data, t_command cmd, int fd)
{
	char	*tmp;
	int		size;

	size = get_size(fd, data);
	if (data->error)
		return (0);
	if (data->type == TYPE_ASCII)
	{
		tmp = ft_strjoinaf1(ft_strjoinaf12(ft_strjoinaf1(
			ft_strjoin("150 Opening ASCII mode data connection for ",
				cmd.argument), " ("), ft_itoa_base(size, 10)), " bytes).\r\n");
	}
	else
	{
		tmp = ft_strjoinaf1(ft_strjoinaf12(ft_strjoinaf1(
			ft_strjoin("150 Opening BINARY mode data connection for ",
				cmd.argument), " ("), ft_itoa_base(size, 10)), " bytes).\r\n");
	}
	ft_putstr_fd(tmp, data->pi_socket);
	free(tmp);
	return (1);
}

void			func_retr(t_data *data)
{
	t_command	cmd;
	int			fd;
	int			cs;

	if (!data->logged_in)
		return (setret(data, 530, ERROR_NOT_LOGGED, 1));
	if (!data->data_connection_on)
		return (setret(data, 425, " Use PASV first.", 1));
	cmd = *(data->cmd);
	if (!cmd.argument)
		return (setret(data, 550, " Failed to open file.", 1));
	if ((fd = open_wrapper(data, cmd.argument, O_RDONLY, 0)) == -1)
		return (setret(data, 550, " Failed to open file.", 1));
	cs = init_accept(data);
	if (data->error)
		return (setret(data, 550, " Failed to accept socket", 1));
	if (!put_open_binary(data, cmd, fd))
		return ;
	do_read_write(data, fd, cs);
	close(cs);
	close(fd);
	setret(data, 226, " Transfer complete.", -2);
	close_data_connection(data);
}

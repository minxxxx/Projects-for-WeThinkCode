/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_stor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 13:04:31 by jcamhi            #+#    #+#             */
/*   Updated: 2017/08/31 13:06:17 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

static void	fml(int *fd, char *ptr, char **oldptr)
{
	write(*fd, *oldptr, ptr - *oldptr);
	write(*fd, "\n", 1);
	*oldptr = ptr + 2;
}

static void	do_read_write(t_data *data, int cs, int fd)
{
	char	buf[BUFF_SIZE_2];
	int		r;
	char	*ptr;
	char	*oldptr;

	while ((r = read(cs, buf, BUFF_SIZE_2 - 1)) > 0)
	{
		buf[r] = '\0';
		if (data->type == TYPE_BINARY)
			write(fd, buf, r);
		else
		{
			ptr = buf;
			oldptr = buf;
			while (ptr)
			{
				if ((ptr = ft_strchr(oldptr, '\r')) && *(ptr + 1) == '\n')
					fml(&fd, ptr, &oldptr);
				else if (oldptr)
					write(fd, oldptr, ft_strlen(oldptr));
			}
		}
	}
}

void		func_stor(t_data *data)
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
	if ((fd = open_wrapper(data,
		cmd.argument, O_WRONLY | O_CREAT | O_TRUNC, 0666)) == -1)
		return (setret(data, 550, " Failed to open file.", 1));
	cs = init_accept(data);
	ft_putstr_fd("150 Ok to send data.\r\n", data->pi_socket);
	do_read_write(data, cs, fd);
	close(fd);
	close(cs);
	data->return_code = 226;
	data->commentaire = " Transfer complete.";
	close_data_connection(data);
}

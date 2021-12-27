/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 13:04:03 by jcamhi            #+#    #+#             */
/*   Updated: 2017/08/31 13:04:09 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

void	send_data_list(t_data *data, char *str)
{
	int					cs;
	struct sockaddr_in	csin;
	unsigned int		cslen;

	if (data->data_connection_on)
	{
		if ((cs = accept(data->data_connection_socket, (struct sockaddr *)&csin,
						&cslen)) == -1)
		{
			ft_putstr_fd("Error while trying to accept a socket.\n", 2);
			return ;
		}
		ft_putstr_fd("150 Here comes the directory listing.\r\n",
				data->pi_socket);
		ft_putstr_fd(str, cs);
		close(cs);
	}
}

int		init_accept(t_data *data)
{
	int					cs;
	struct sockaddr_in	csin;
	unsigned int		cslen;

	if (data->data_connection_on)
	{
		if ((cs = accept(data->data_connection_socket, (struct sockaddr *)&csin,
						&cslen)) == -1)
		{
			ft_putstr_fd("Error while trying to accept a socket.\n", 2);
			data->error = 1;
			return (0);
		}
		return (cs);
	}
	data->error = 1;
	return (0);
}

void	close_data_connection(t_data *data)
{
	if (data->data_connection_on)
	{
		close(data->data_connection_socket);
		data->data_connection_on = 0;
	}
}

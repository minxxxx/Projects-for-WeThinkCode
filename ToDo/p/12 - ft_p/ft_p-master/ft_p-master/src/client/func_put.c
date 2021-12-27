/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_put.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 15:55:12 by jcamhi            #+#    #+#             */
/*   Updated: 2017/08/30 16:00:59 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

static int	get_fd(t_data *data, char *file)
{
	int	fd;

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_printf("Error while trying to open file %s\n", file);
		data->error = 1;
		return (-1);
	}
	return (fd);
}

static int	begin(t_data *data, int *data_socket, int *fd)
{
	if (!data->cmd.cmd_tab[1] || !data->cmd.cmd_tab[2])
	{
		ft_printf("Usage: put local remote\n");
		data->error = 1;
		return (1);
	}
	*data_socket = set_passive_mode(data);
	if (data->error)
	{
		ft_printf("Error while trying to open a passive connection");
		return (1);
	}
	if ((*fd = get_fd(data, (data->cmd).cmd_tab[1])) == -1)
	{
		close(*data_socket);
		return (1);
	}
	return (0);
}

static void	fln(t_data *data, t_answer answer)
{
	free_answer(answer);
	return (set_error_and_ret(data, NULL, NULL));
}

void		func_put(t_data *data)
{
	int			data_socket;
	char		*send;
	t_answer	answer;
	int			fd;

	if (begin(data, &data_socket, &fd))
		return ;
	send = build_request(NAME_RFC_PUT, (data->cmd).cmd_tab[2]);
	write(data->socket, send, ft_strlen(send));
	free(send);
	answer = get_answer(data);
	if (answer.error <= 0)
		error_connection(data);
	ft_printf("%s\n", answer.str);
	if (answer.code / 100 > 2)
		return (fln(data, answer));
	redirect_data(fd, data_socket);
	close(data_socket);
	free_answer(answer);
	answer = get_answer(data);
	if (answer.error <= 0)
		error_connection(data);
	ft_printf("%s\n", answer.str);
	free_answer(answer);
}

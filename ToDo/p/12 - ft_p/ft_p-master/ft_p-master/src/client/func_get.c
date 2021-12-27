/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 15:13:03 by jcamhi            #+#    #+#             */
/*   Updated: 2017/08/30 16:10:47 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

static int	get_fd(t_data *data, char *file)
{
	int	fd;

	if (!file)
		return (1);
	if ((fd = open(file, O_WRONLY | O_CREAT, 0666)) == -1)
	{
		ft_printf("Error while trying to open file %s\n", file);
		data->error = 1;
		return (-1);
	}
	return (fd);
}

static void	send_get_message(t_data *data, t_answer *answer)
{
	char		*send;

	send = build_request(NAME_RFC_GET, (data->cmd).cmd_tab[1]);
	write(data->socket, send, ft_strlen(send));
	free(send);
	*answer = get_answer(data);
}

static void	do_rac(t_data *data, int data_socket, t_answer *answer, int fd)
{
	redirect_data(data_socket, fd);
	close(data_socket);
	free_answer(*answer);
	*answer = get_answer(data);
}

static void	fln(t_data *data, int data_socket, t_answer *answer, int fd)
{
	do_rac(data, data_socket, answer, fd);
	if (answer->error <= 0)
		error_connection(data);
	ft_printf("%s\n", answer->str);
	free_answer(*answer);
}

void		func_get(t_data *data)
{
	int			data_socket;
	t_answer	answer;
	int			fd;

	if (!data->cmd.cmd_tab[1])
		return (set_error_and_ret(data, "Usage", "get remote [local]"));
	data_socket = set_passive_mode(data);
	if (data->error)
		return (pem(NULL, "Error while trying to open a passive connection"));
	if ((fd = get_fd(data, (data->cmd).cmd_tab[2])) == -1)
	{
		close(data->socket);
		return (set_error_and_ret(data, NULL, NULL));
	}
	send_get_message(data, &answer);
	if (answer.error <= 0)
		error_connection(data);
	ft_printf("%s\n", answer.str);
	if (answer.code / 100 > 2)
	{
		free_answer(answer);
		return (set_error_and_ret(data, NULL, NULL));
	}
	fln(data, data_socket, &answer, fd);
}

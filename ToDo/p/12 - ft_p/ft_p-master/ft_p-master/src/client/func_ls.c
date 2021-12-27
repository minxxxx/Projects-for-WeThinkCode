/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 15:21:48 by jcamhi            #+#    #+#             */
/*   Updated: 2017/08/30 15:26:46 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

static void	redir_close_free(int data_socket, t_answer answer)
{
	redirect_data(data_socket, 1);
	close(data_socket);
	free_answer(answer);
}

void		func_ls(t_data *data)
{
	int			data_socket;
	char		*send;
	t_answer	answer;

	data_socket = set_passive_mode(data);
	if (data->error)
		return (pem(NULL, "Error while trying to open a passive connection"));
	send = build_request(NAME_RFC_LS, (data->cmd).cmd_tab[1]);
	write(data->socket, send, ft_strlen(send));
	free(send);
	answer = get_answer(data);
	if (answer.error <= 0)
		error_connection(data);
	ft_printf("%s\n", answer.str);
	if (answer.code / 100 > 2)
	{
		free_answer(answer);
		return (set_error_and_ret(data, NULL, NULL));
	}
	redir_close_free(data_socket, answer);
	answer = get_answer(data);
	if (answer.error <= 0)
		error_connection(data);
	ft_printf("%s\n", answer.str);
	free_answer(answer);
}

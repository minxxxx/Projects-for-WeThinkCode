/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_quit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 16:01:46 by jcamhi            #+#    #+#             */
/*   Updated: 2017/08/30 16:01:49 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

void	func_quit(t_data *data)
{
	char		*send;
	t_answer	answer;

	send = build_request(NAME_RFC_QUIT, "");
	write(data->socket, send, ft_strlen(send));
	free(send);
	answer = get_answer(data);
	if (answer.error <= 0)
		error_connection(data);
	ft_printf("%s\n", answer.str);
	free_answer(answer);
	close(data->socket);
	reinit_data(data);
	exit(0);
}

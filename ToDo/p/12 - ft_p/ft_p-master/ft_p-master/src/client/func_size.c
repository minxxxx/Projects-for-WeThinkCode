/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 15:30:51 by jcamhi            #+#    #+#             */
/*   Updated: 2017/08/30 15:32:50 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

void	func_size(t_data *data)
{
	char		*send;
	t_answer	answer;

	if (!(data->cmd).cmd_tab[1])
	{
		ft_printf("Usage: size file\n");
		data->error = 1;
		return ;
	}
	send = build_request(NAME_RFC_SIZE, (data->cmd).cmd_tab[1]);
	write(data->socket, send, ft_strlen(send));
	free(send);
	answer = get_answer(data);
	if (answer.error <= 0)
		error_connection(data);
	if (answer.code / 100 > 2)
	{
		ft_printf("%s\n", answer.str);
		data->error = 1;
		return ;
	}
	ft_printf("Size of remote file %s: %d\n",
			(data->cmd).cmd_tab[1], ft_atoi(answer.commentaire));
	free_answer(answer);
	return ;
}

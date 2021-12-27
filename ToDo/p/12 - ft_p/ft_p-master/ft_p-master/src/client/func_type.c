/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 16:02:20 by jcamhi            #+#    #+#             */
/*   Updated: 2017/08/30 16:05:03 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>
#define ER "type {{I || IMAGE || B || BINARY} || {A || ASCII}}"

void	func_type(t_data *data)
{
	char		*send;
	char		*arg;
	char		*str;
	t_answer	answer;

	str = (data->cmd).cmd_tab[1];
	if (ft_strequ(str, "IMAGE") || ft_strequ(str, "BINARY")
			|| ft_strequ(str, "I") || ft_strequ(str, "B"))
		arg = ft_strdup("I");
	else if (ft_strequ(str, "ASCII") || ft_strequ(str, "A"))
		arg = ft_strdup("A");
	else
		return (set_error_and_ret(data, "Usage", ER));
	send = build_request(NAME_RFC_TYPE, arg);
	free(arg);
	write(data->socket, send, ft_strlen(send));
	free(send);
	answer = get_answer(data);
	if (answer.error <= 0)
		error_connection(data);
	ft_printf("%s\n", answer.str);
	if (answer.code / 100 > 2)
		data->error = 1;
	free_answer(answer);
	return ;
}

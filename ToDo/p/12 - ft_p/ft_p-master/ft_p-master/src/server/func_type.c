/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 13:04:35 by jcamhi            #+#    #+#             */
/*   Updated: 2017/08/31 13:04:36 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

void	func_type(t_data *data)
{
	t_command	cmd;

	if (!data->logged_in)
		return (setret(data, 530, " Please login with USER and PASS", 1));
	cmd = *(data->cmd);
	if (!cmd.argument)
		return (setret(data, 500, " Unrecognised TYPE command.", 1));
	if (cmd.argument[0] == 'I')
	{
		data->type = TYPE_BINARY;
		data->commentaire = " Switching to Binary mode.";
	}
	else if (cmd.argument[0] == 'A')
	{
		data->type = TYPE_ASCII;
		data->commentaire = " Switching to ASCII mode.";
	}
	else
		return (setret(data, 500, " Unrecognised TYPE command.", 1));
	data->return_code = 200;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_user.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 13:04:36 by jcamhi            #+#    #+#             */
/*   Updated: 2017/08/31 13:04:37 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

void	already_logged(t_data *data, t_command cmd)
{
	if (ft_strequ(data->usr, cmd.argument))
		return (setret(data, 331, " Any password will do.", 1));
	else
		return (setret(data, 530, " Can't change to another user.", 1));
}

void	func_user(t_data *data)
{
	t_command	cmd;
	char		*pass;

	cmd = *(data->cmd);
	if (cmd.argument == NULL)
		return (setret(data, 501, NULL, 1));
	if (data->logged_in)
		return (already_logged(data, cmd));
	pass = get_pass(cmd.argument, data);
	if (data->error)
		return (setret(data, 530, NULL, -2));
	if (pass)
	{
		data->usr = cmd.argument;
		data->logged_in = 0;
		free(pass);
		return (setret(data, 331, " Please specify a password.", -2));
	}
	else
	{
		setret(data, 230, " User successfully logged in.", -2);
		data->usr = cmd.argument;
		data->logged_in = 1;
	}
}

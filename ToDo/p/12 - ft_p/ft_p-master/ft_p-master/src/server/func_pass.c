/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_pass.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 13:04:22 by jcamhi            #+#    #+#             */
/*   Updated: 2017/08/31 13:04:23 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

int		is_valid(t_data *data, t_command cmd)
{
	if (cmd.argument == NULL)
	{
		setret(data, 501, NULL, 1);
		return (0);
	}
	if (data->usr == NULL)
	{
		setret(data, 503, " Login with USER first.", 1);
		return (0);
	}
	if (data->logged_in == 1)
	{
		setret(data, 230, " Already logged in.", 1);
		return (0);
	}
	return (1);
}

void	func_pass(t_data *data)
{
	t_command	cmd;
	char		*pass;

	cmd = *(data->cmd);
	if (!is_valid(data, cmd))
		return ;
	pass = get_pass(data->usr, data);
	if (data->error || !pass)
		return (setret(data, 530, NULL, -1));
	if (ft_strequ(pass, cmd.argument))
	{
		data->logged_in = 1;
		free(pass);
		return (setret(data, 230, " Login successful.", 0));
	}
	else
	{
		free(data->usr);
		data->usr = NULL;
		data->logged_in = 0;
		free(pass);
		return (setret(data, 530, " Login incorrect.", 1));
	}
}

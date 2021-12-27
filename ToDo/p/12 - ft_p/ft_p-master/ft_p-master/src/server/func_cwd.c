/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_cwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 13:03:34 by jcamhi            #+#    #+#             */
/*   Updated: 2017/08/31 13:04:16 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

void	func_cwd(t_data *data)
{
	t_command	cmd;

	if (!data->logged_in)
		return (setret(data, 530, ERROR_NOT_LOGGED, 1));
	cmd = *(data->cmd);
	if (!cmd.argument || !can_be_oppenedir(cmd.argument, data->exec_path)
		|| chdir(cmd.argument) == -1)
	{
		data->return_code = 550;
		data->commentaire = " Failed to change directory.";
		data->error = 1;
		return ;
	}
	data->return_code = 250;
	data->commentaire = " Directory successfully changed";
	return ;
}

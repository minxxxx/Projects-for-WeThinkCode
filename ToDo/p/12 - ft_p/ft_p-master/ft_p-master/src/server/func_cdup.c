/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_cdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 13:03:51 by jcamhi            #+#    #+#             */
/*   Updated: 2017/08/31 13:04:12 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

void	func_cdup(t_data *data)
{
	if (!data->logged_in)
		return (setret(data, 530, ERROR_NOT_LOGGED, 1));
	if (!can_be_oppenedir("..", data->exec_path))
		return (setret(data, 550, " You can't go there !", 1));
	if (chdir("..") == -1)
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

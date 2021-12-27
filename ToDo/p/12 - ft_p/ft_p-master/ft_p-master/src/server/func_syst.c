/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_syst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 13:04:32 by jcamhi            #+#    #+#             */
/*   Updated: 2017/08/31 13:04:34 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

void	func_syst(t_data *data)
{
	if (!data->logged_in)
		return (setret(data, 530, ERROR_NOT_LOGGED, 1));
	data->return_code = 215;
	data->commentaire = SYSTEM_NAME_AN;
	return ;
}

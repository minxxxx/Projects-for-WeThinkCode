/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_feat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 13:03:53 by jcamhi            #+#    #+#             */
/*   Updated: 2017/08/31 13:05:40 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

void	func_feat(t_data *data)
{
	if (!data->logged_in)
		return (setret(data, 530, ERROR_NOT_LOGGED, 1));
	data->return_code = 211;
	data->commentaire = "-Features:\r\n SIZE\r\n MDTM\r\n211 End";
	return ;
}

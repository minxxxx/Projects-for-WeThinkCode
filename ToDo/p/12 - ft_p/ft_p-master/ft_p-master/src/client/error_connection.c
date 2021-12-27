/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_connection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 15:21:14 by jcamhi            #+#    #+#             */
/*   Updated: 2017/08/30 15:21:15 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

void	error_connection(t_data *data)
{
	ft_printf("Error : It seems you have been disconnected.\n");
	close(data->socket);
	exit(EXIT_FAILURE);
}

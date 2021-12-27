/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 16:14:53 by jcamhi            #+#    #+#             */
/*   Updated: 2017/08/30 16:14:54 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

void	pem(char *filename, char *message)
{
	if (filename)
	{
		ft_putstr_fd(filename, 2);
		ft_putstr_fd(": ", 2);
	}
	if (message)
		ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
}

int		pemr(char *filename, char *message)
{
	pem(filename, message);
	return (0);
}

void	set_error_and_ret(t_data *data, char *filename, char *message)
{
	data->error = 1;
	if (message)
		pem(filename, message);
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 13:04:53 by jcamhi            #+#    #+#             */
/*   Updated: 2017/08/31 13:04:56 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

void	print_error_message(char *filename, char *message)
{
	ft_putstr_fd(filename, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
}

int		pemr(char *filename, char *message)
{
	print_error_message(filename, message);
	return (0);
}

void	remove_cr(char *str)
{
	size_t	n;

	if (!str)
		return ;
	n = ft_strlen(str);
	if (n < 1)
		return ;
	if (str[n - 1] == 13)
	{
		str[n - 1] = '\0';
		return ;
	}
}

void	setret(t_data *data, int ret, char *com, int error)
{
	data->return_code = ret;
	if (com)
		data->commentaire = com;
	if (error != -1)
		data->error = error;
	return ;
}

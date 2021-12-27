/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_connection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 15:36:11 by jcamhi            #+#    #+#             */
/*   Updated: 2017/08/30 15:36:12 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

void	redirect_data(int data_fd, int redir_fd)
{
	char	buff[BUFF_SIZE + 1];
	int		r;

	while ((r = read(data_fd, buff, BUFF_SIZE)))
		write(redir_fd, buff, r);
}

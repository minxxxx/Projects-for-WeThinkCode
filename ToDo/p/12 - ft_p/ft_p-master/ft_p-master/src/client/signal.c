/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 15:35:40 by jcamhi            #+#    #+#             */
/*   Updated: 2017/08/30 15:35:40 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

void	sigint(int sig)
{
	t_data	*data;

	(void)sig;
	data = singleton_data(NULL);
	ft_printf("\n");
	print_prompt(data, 0);
}

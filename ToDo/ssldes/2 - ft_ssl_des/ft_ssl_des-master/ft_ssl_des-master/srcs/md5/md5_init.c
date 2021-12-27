/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 17:34:08 by jcamhi            #+#    #+#             */
/*   Updated: 2018/11/12 17:31:32 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

void	initialize_buffer(uint *buffer)
{
	buffer[0] = 0x67452301u;
	buffer[1] = 0xefcdab89u;
	buffer[2] = 0x98badcfeu;
	buffer[3] = 0x10325476u;
}

void	initialize_t(uint t[65])
{
	uint i;

	i = 1;
	while (i <= 64)
	{
		t[i] = 4294967296.0 * fabs(sin(i));
		i++;
	}
}

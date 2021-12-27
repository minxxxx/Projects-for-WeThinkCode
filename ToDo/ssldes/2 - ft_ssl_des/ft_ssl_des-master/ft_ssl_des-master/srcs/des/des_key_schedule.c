/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_key_schedule.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:31:17 by jcamhi            #+#    #+#             */
/*   Updated: 2018/11/12 17:31:18 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

t_uint48	calculate_key(uint64_t c, uint64_t d)
{
	t_uint48	ret;
	uint64_t	pair;
	uint64_t	reti;

	pair = c | end_conv_64(end_conv_64(d) >> 28);
	permutate((void*)&pair, (void*)&reti, g_des_pc_two, 48);
	ret.x = reti;
	return (ret);
}

void		compute_key_schedule(t_uint48 out[16], uint64_t key)
{
	uint32_t	c;
	uint32_t	d;
	size_t		i;

	c = 0;
	d = 0;
	permutate((void*)&key, (void*)&c, g_des_pc_one_left, 28);
	permutate((void*)&key, (void*)&d, g_des_pc_one_right, 28);
	i = 0;
	while (i < 16)
	{
		if (g_des_lshift[i] == 1)
		{
			permutate((void*)&c, (void*)&c, g_des_rotl_1, 28);
			permutate((void*)&d, (void*)&d, g_des_rotl_1, 28);
		}
		else
		{
			permutate((void*)&c, (void*)&c, g_des_rotl_2, 28);
			permutate((void*)&d, (void*)&d, g_des_rotl_2, 28);
		}
		i++;
		out[i - 1] = calculate_key(c, d);
	}
}

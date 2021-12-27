/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_encoding_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:31:02 by jcamhi            #+#    #+#             */
/*   Updated: 2018/11/12 17:31:02 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

void		swap_ks(t_uint48 ks[16])
{
	t_uint48	cpy[16];

	ft_memcpy(cpy, ks, 16 * sizeof(t_uint48));
	ks[0] = cpy[15];
	ks[1] = cpy[14];
	ks[2] = cpy[13];
	ks[3] = cpy[12];
	ks[4] = cpy[11];
	ks[5] = cpy[10];
	ks[6] = cpy[9];
	ks[7] = cpy[8];
	ks[8] = cpy[7];
	ks[9] = cpy[6];
	ks[10] = cpy[5];
	ks[11] = cpy[4];
	ks[12] = cpy[3];
	ks[13] = cpy[2];
	ks[14] = cpy[1];
	ks[15] = cpy[0];
}

void		remove_padding(const uint8_t *data, size_t *datalen, uint8_t *ret)
{
	int	padd_size;

	padd_size = data[*datalen - 1];
	ret[*datalen - padd_size] = '\0';
	*datalen = *datalen - padd_size;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   descbc3algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvinp@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 15:37:22 by apakhomo          #+#    #+#             */
/*   Updated: 2018/02/03 15:37:23 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_des.h"

void	des3cbc_e(UC **inp, size_t size, t_ssl *data)
{
	size_t			a;
	unsigned long	temp;
	unsigned long	keys_1[16];
	unsigned long	keys_2[16];
	unsigned long	keys_3[16];

	a = 0;
	make_keys(keys_1, data->des3_key1, DES_E);
	make_keys(keys_2, data->des3_key2, DES_D);
	make_keys(keys_3, data->des3_key3, DES_E);
	while (a < size)
	{
		temp = ecb_get_8((*inp) + a);
		temp ^= data->master_iv;
		temp = ecb_body(temp, keys_1);
		temp = ecb_body(temp, keys_2);
		temp = ecb_body(temp, keys_3);
		data->master_iv = temp;
		ecb_put_8((*inp) + a, temp);
		a += 8;
	}
}

void	des3cbc_d(UC **inp, size_t size, t_ssl *data, UL iv)
{
	size_t			a;
	unsigned long	temp;
	unsigned long	keys_1[16];
	unsigned long	keys_2[16];
	unsigned long	keys_3[16];

	a = 0;
	make_keys(keys_1, data->des3_key3, DES_D);
	make_keys(keys_2, data->des3_key2, DES_E);
	make_keys(keys_3, data->des3_key1, DES_D);
	while (a < size)
	{
		temp = ecb_get_8((*inp) + a);
		iv = temp;
		temp = ecb_body(temp, keys_1);
		temp = ecb_body(temp, keys_2);
		temp = ecb_body(temp, keys_3);
		temp ^= data->master_iv;
		data->master_iv = iv;
		ecb_put_8((*inp) + a, temp);
		a += 8;
	}
}

void	des3cbc_e_inp(t_ssl *data, UC **inp, UC **out, size_t *size)
{
	size_t			a;
	unsigned char	bit;
	unsigned char	*temp;

	a = ((*size / 8) + 1) * 8;
	bit = a - *size;
	if ((temp = ft_memalloc(a + 1)) == NULL)
		exit_error(errno, *inp);
	ft_memcpy(temp, *inp, *size);
	free(*inp);
	*inp = temp;
	while (*size < a)
		(*inp)[(*size)++] = bit;
	des3cbc_e(inp, *size, data);
	if (data->b64 == 1)
	{
		*out = base64encode(*inp, size);
		free(*inp);
	}
	else
		*out = *inp;
}

void	des3cbc_d_inp(t_ssl *data, UC **inp, UC **out, size_t *size)
{
	size_t			a;
	unsigned char	bit;

	if (data->b64 == 1)
	{
		*out = base64decode(*inp, size);
		free(*inp);
		*inp = *out;
	}
	des3cbc_d(inp, *size, data, 0);
	bit = (*inp)[(*size) - 1];
	if ((bit >= 1) && (bit <= 8))
	{
		a = *size - bit;
		while (((*inp)[a] == bit) && (a < *size))
			a++;
		if (a == *size)
			(*size) -= bit;
	}
	*out = *inp;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   desecb3algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 15:37:22 by apakhomo          #+#    #+#             */
/*   Updated: 2018/02/03 15:37:23 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_des.h"

void	des3ecb_e(UC **inp, size_t size, t_ssl *data)
{
	size_t			a;
	unsigned long	temp;
	unsigned long	keys_1[16];
	unsigned long	keys_2[16];
	unsigned long	keys_3[16];

	make_keys(keys_1, data->des3_key1, DES_E);
	make_keys(keys_2, data->des3_key2, DES_D);
	make_keys(keys_3, data->des3_key3, DES_E);
	a = 0;
	while (a < size)
	{
		temp = ecb_get_8(*inp + a);
		temp = ecb_body(temp, keys_1);
		temp = ecb_body(temp, keys_2);
		temp = ecb_body(temp, keys_3);
		ecb_put_8(*inp + a, temp);
		a += 8;
	}
}

void	des3ecb_d(UC **inp, size_t size, t_ssl *data)
{
	size_t			a;
	unsigned long	temp;
	unsigned long	keys_1[16];
	unsigned long	keys_2[16];
	unsigned long	keys_3[16];

	make_keys(keys_1, data->des3_key3, DES_D);
	make_keys(keys_2, data->des3_key2, DES_E);
	make_keys(keys_3, data->des3_key1, DES_D);
	a = 0;
	while (a < size)
	{
		temp = ecb_get_8(*inp + a);
		temp = ecb_body(temp, keys_1);
		temp = ecb_body(temp, keys_2);
		temp = ecb_body(temp, keys_3);
		ecb_put_8(*inp + a, temp);
		a += 8;
	}
}

void	des3ecb_e_inp(t_ssl *data, UC **in, UC **out, size_t *size)
{
	size_t			a;
	unsigned char	bit;
	unsigned char	*temp;

	a = ((*size / 8) + 1) * 8;
	bit = a - *size;
	if ((temp = ft_memalloc(a + 1)) == NULL)
		exit_error(errno, *in);
	ft_memcpy(temp, *in, *size);
	free(*in);
	*in = temp;
	while (*size < a)
		(*in)[(*size)++] = bit;
	des3ecb_e(in, *size, data);
	if (data->b64 == 1)
	{
		*out = base64encode(*in, size);
		free(*in);
	}
	else
		*out = *in;
}

void	des3ecb_d_inp(t_ssl *data, UC **in, UC **out, size_t *size)
{
	size_t			a;
	unsigned char	bit;

	if (data->b64 == 1)
	{
		*out = base64decode(*in, size);
		free(*in);
		*in = *out;
	}
	des3ecb_d(in, *size, data);
	bit = (*in)[(*size) - 1];
	if ((bit >= 1) && (bit <= 8))
	{
		a = *size - bit;
		while (((*in)[a] == bit) && (a < *size))
			a++;
		if (a == *size)
			(*size) -= bit;
	}
	*out = *in;
}

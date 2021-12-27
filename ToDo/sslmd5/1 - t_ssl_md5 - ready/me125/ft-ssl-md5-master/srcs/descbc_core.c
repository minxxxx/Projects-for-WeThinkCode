/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   descbc_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 17:18:03 by apakhomo          #+#    #+#             */
/*   Updated: 2018/02/03 17:18:04 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_des.h"

void			cbc_showkey(unsigned long master_key)
{
	int				a;
	unsigned char	c;

	a = 0;
	while (a < 16)
	{
		c = (master_key >> (60 - (a * 4))) & 0xf;
		if (c < 10)
			c += '0';
		else
			c += ('a' - 10);
		write(1, &c, 1);
		a++;
	}
}

void			cbc_print_key(t_ssl ssl)
{
	ft_printf("key=");
	cbc_showkey(ssl.master_key);
	ft_printf("\n");
	ft_printf("iv =");
	cbc_showkey(ssl.master_iv);
	ft_printf("\n");
}

void			cbc_encrypt(UC **inp, size_t size, t_ssl *ssl, int flag)
{
	size_t			i;
	unsigned long	iv;
	unsigned long	temp;
	unsigned long	keys[16];

	make_keys(keys, ssl->master_key, flag);
	i = 0;
	iv = ssl->master_iv;
	while (i < size)
	{
		temp = ecb_get_8((*inp) + i);
		temp ^= iv;
		temp = ecb_body(temp, keys);
		iv = temp;
		ecb_put_8((*inp) + i, temp);
		i += 8;
	}
}

void			cbc_decrypt(UC **inp, size_t size, t_ssl *ssl, int flag)
{
	unsigned long	data;
	unsigned long	keys[16];
	size_t			i;
	unsigned long	iv;
	unsigned long	next_iv;

	make_keys(keys, ssl->master_key, flag);
	i = 0;
	iv = ssl->master_iv;
	while (i < size)
	{
		data = ecb_get_8((*inp) + i);
		next_iv = data;
		data = ecb_body(data, keys);
		data ^= iv;
		iv = next_iv;
		ecb_put_8((*inp) + i, data);
		i += 8;
	}
}

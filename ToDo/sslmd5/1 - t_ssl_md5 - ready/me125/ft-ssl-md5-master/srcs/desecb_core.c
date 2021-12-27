/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   desecb_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 14:10:12 by apakhomo          #+#    #+#             */
/*   Updated: 2018/02/03 14:10:12 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_des.h"

unsigned long	ecb_body(UL inp, UL keys[16])
{
	unsigned long	temp;
	unsigned long	left0;
	unsigned long	right0;
	unsigned long	right1;
	int				a;

	temp = make_gip(inp);
	left0 = (temp >> 32) & 0xffffffff;
	right0 = temp & 0xffffffff;
	a = 0;
	while (a < 16)
	{
		temp = make_gsb(make_gep(right0) ^ keys[a]);
		right1 = left0 ^ make_gpp(temp);
		left0 = right0;
		right0 = right1;
		a++;
	}
	return (make_gfp((right1 << 32) + left0));
}

unsigned long	ecb_get_8(unsigned char *data)
{
	int				a;
	unsigned long	ret;

	a = 0;
	ret = 0;
	while (a < 8)
	{
		ret <<= 8;
		ret += data[a];
		a++;
	}
	return (ret);
}

void			ecb_put_8(unsigned char *data, UL ul64)
{
	int				a;
	unsigned char	c;

	a = 0;
	while (a < 8)
	{
		c = (ul64 >> (56 - (a * 8))) & 0xff;
		data[a] = c;
		a++;
	}
}

void			ecb_core(UC **inp, size_t size, UL mk, int flag)
{
	unsigned long	data;
	unsigned long	keys[16];
	size_t			a;

	make_keys(keys, mk, flag);
	a = 0;
	while (a < size)
	{
		data = ecb_get_8(*inp + a);
		data = ecb_body(data, keys);
		ecb_put_8(*inp + a, data);
		a += 8;
	}
}

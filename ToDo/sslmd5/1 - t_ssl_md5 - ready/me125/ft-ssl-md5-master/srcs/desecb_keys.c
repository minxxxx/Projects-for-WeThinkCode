/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   desecb_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 14:40:56 by apakhomo          #+#    #+#             */
/*   Updated: 2018/02/03 14:40:56 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_des.h"
#include "des.h"

unsigned long	make_gkp(unsigned long a)
{
	int				i;
	unsigned long	ret;
	unsigned long	temp;

	ret = 0;
	i = 0;
	while (i < 56)
	{
		temp = (a >> (64 - g_key_permut[i])) & 1;
		ret <<= 1;
		ret += temp;
		i++;
	}
	ret <<= 8;
	return (ret);
}

unsigned long	mutat_shift_left(unsigned long key, int bits)
{
	unsigned long	ret;
	unsigned long	temp;
	unsigned long	mutat;

	temp = bits;
	mutat = 0;
	while (temp--)
		mutat = (mutat << 1) + 1;
	temp = (key >> (bits - 1)) & 1;
	ret = ((key << 1) + temp) & mutat;
	return (ret);
}

void			make_half_keys(unsigned long half_keys[16], UL starter)
{
	int				i;
	unsigned char	shift;
	unsigned long	new_half;

	i = 0;
	while (i < 16)
	{
		shift = g_key_shift[i];
		while (shift--)
		{
			new_half = mutat_shift_left(starter, 28);
			starter = new_half;
		}
		half_keys[i] = new_half;
		i++;
	}
}

unsigned long	make_gcp(unsigned long c_half, unsigned long d_half)
{
	int				i;
	unsigned long	after;
	unsigned long	before;

	before = (c_half << 28) + d_half;
	i = 0;
	after = 0;
	while (i < 48)
	{
		after <<= 1;
		after += ((before >> (56 - g_compress_permut[i])) & 1);
		i++;
	}
	return (after);
}

void			make_keys(unsigned long keys[16], UL master_key, int flag)
{
	int				a;
	unsigned long	gkp;
	unsigned long	c_half_keys[16];
	unsigned long	d_half_keys[16];

	gkp = make_gkp(master_key);
	make_half_keys(c_half_keys, (gkp >> 36) & 0xfffffff);
	make_half_keys(d_half_keys, (gkp >> 8) & 0xfffffff);
	a = 0;
	while (a < 16)
	{
		gkp = a;
		if (flag == 1)
			gkp = 15 - a;
		keys[gkp] = make_gcp(c_half_keys[a], d_half_keys[a]);
		a++;
	}
}

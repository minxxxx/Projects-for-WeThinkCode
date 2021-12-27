/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   desecb_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 14:33:47 by apakhomo          #+#    #+#             */
/*   Updated: 2018/02/03 14:33:47 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_des.h"
#include "des.h"

unsigned long	make_gip(unsigned long gip)
{
	unsigned long	ret;
	int				i;

	i = 0;
	ret = 0;
	while (i < 64)
	{
		ret <<= 1;
		ret += (gip >> (64 - g_init_permut[i])) & 1;
		i++;
	}
	return (ret);
}

unsigned long	make_gep(unsigned long gep)
{
	unsigned long	ret;
	unsigned long	temp;
	int				a;

	a = 0;
	ret = 0;
	while (a < 48)
	{
		temp = (gep >> (32 - g_expand_permut[a])) & 1;
		ret <<= 1;
		ret += temp;
		a++;
	}
	return (ret);
}

unsigned long	make_gsb(unsigned long gsb)
{
	int				i;
	int				row;
	int				col;
	unsigned long	temp;
	unsigned long	ret;

	i = 0;
	ret = 0;
	while (i < 8)
	{
		temp = (gsb >> (42 - (i * 6))) & 0x3f;
		row = ((temp >> 5) << 1) + (temp & 1);
		col = (temp >> 1) & 0xf;
		temp = g_s_boxes[i][row * 16 + col];
		ret <<= 4;
		ret += temp;
		i++;
	}
	return (ret);
}

unsigned long	make_gpp(unsigned long gpp)
{
	int				i;
	unsigned long	temp;
	unsigned long	ret;

	i = 0;
	ret = 0;
	while (i < 32)
	{
		temp = (gpp >> (32 - g_pbox_permut[i])) & 1;
		ret <<= 1;
		ret += temp;
		i++;
	}
	return (ret);
}

unsigned long	make_gfp(unsigned long gfp)
{
	int				i;
	unsigned long	temp;
	unsigned long	ret;

	i = 0;
	ret = 0;
	while (i < 64)
	{
		temp = (gfp >> (64 - g_final_permut[i])) & 1;
		ret <<= 1;
		ret += temp;
		i++;
	}
	return (ret);
}

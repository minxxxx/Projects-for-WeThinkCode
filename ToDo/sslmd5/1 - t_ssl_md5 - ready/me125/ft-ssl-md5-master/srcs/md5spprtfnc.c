/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5spprtfnc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 10:07:36 by apakhomo          #+#    #+#             */
/*   Updated: 2018/02/03 10:07:37 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"
#include "md5.h"

ULL			getu32(unsigned char *addr)
{
	return (((((unsigned long)addr[3] << 8) | addr[2]) << 8)
		| addr[1]) << 8 | addr[0];
}

void		putu32(ULL data, unsigned char *addr)
{
	addr[0] = (unsigned char)data;
	addr[1] = (unsigned char)(data >> 8);
	addr[2] = (unsigned char)(data >> 16);
	addr[3] = (unsigned char)(data >> 24);
}

void		md5transform1(t_mds *md, int i)
{
	while (++i < 64)
	{
		if (i < 16)
			md->flag = (i % 4) + 1;
		else if (i > 15 && i < 32)
			md->flag = (i % 4) + 5;
		else if (i > 31 && i < 48)
			md->flag = (i % 4) + 9;
		else if (i > 47 && i < 64)
			md->flag = (i % 4) + 13;
		func1(md, md->in[g_box_ini[i]] + g_box_data[i], g_box_last[i]);
	}
}

void		md5transform(ULL buf[], unsigned char inraw[])
{
	t_mds	md;
	int		i;

	i = -1;
	while (16 > ++i)
		md.in[i] = getu32(inraw + 4 * i);
	md.a = buf[0];
	md.b = buf[1];
	md.c = buf[2];
	md.d = buf[3];
	md5transform1(&md, -1);
	buf[0] += md.a;
	buf[1] += md.b;
	buf[2] += md.c;
	buf[3] += md.d;
}

void		func6(t_mds *md, ULL val, int l)
{
	if (md->flag == 16)
	{
		md->b += F4(md->c, md->d, md->a) + val;
		md->b &= 0xffffffff;
		md->b = md->b << l | md->b >> (32 - l);
		md->b += md->c;
	}
}

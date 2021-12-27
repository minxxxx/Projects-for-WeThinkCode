/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5algocore.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 10:07:36 by apakhomo          #+#    #+#             */
/*   Updated: 2018/02/03 10:07:37 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"

void		md5init(t_md5 *md5data)
{
	md5data->buf[0] = 0x67452301;
	md5data->buf[1] = 0xefcdab89;
	md5data->buf[2] = 0x98badcfe;
	md5data->buf[3] = 0x10325476;
	md5data->bits[0] = 0;
	md5data->bits[1] = 0;
}

UC			*md5update_while(t_md5 *md5data, unsigned char *buf, unsigned *len)
{
	while (*len >= 64)
	{
		ft_memcpy(md5data->in, buf, 64);
		md5transform(md5data->buf, md5data->in);
		buf += 64;
		*len -= 64;
	}
	return (buf);
}

void		md5update(t_md5 *md5data, unsigned char *buf, unsigned len)
{
	ULL				t;
	unsigned char	*p;

	t = md5data->bits[0];
	if ((md5data->bits[0] = (t + ((ULL)len << 3)) & 0xffffffff) < t)
		md5data->bits[1]++;
	md5data->bits[1] += len >> 29;
	t = (t >> 3) & 0x3f;
	if (t)
	{
		p = md5data->in + t;
		t = 64 - t;
		if (len < t)
		{
			ft_memcpy(p, buf, len);
			return ;
		}
		ft_memcpy(p, buf, t);
		md5transform(md5data->buf, md5data->in);
		buf += t;
		len -= t;
	}
	buf = md5update_while(md5data, buf, &len);
	ft_memcpy(md5data->in, buf, len);
}

void		md5final(unsigned char digest[], t_md5 *md5data)
{
	unsigned		count;
	unsigned char	*p;

	count = (md5data->bits[0] >> 3) & 0x3F;
	p = md5data->in + count;
	*p++ = 0x80;
	count = 64 - 1 - count;
	if (count < 8)
	{
		ft_memset(p, 0, count);
		md5transform(md5data->buf, md5data->in);
		ft_memset(md5data->in, 0, 56);
	}
	else
		ft_memset(p, 0, count - 8);
	putu32(md5data->bits[0], md5data->in + 56);
	putu32(md5data->bits[1], md5data->in + 60);
	md5transform(md5data->buf, md5data->in);
	putu32(md5data->buf[0], digest);
	putu32(md5data->buf[1], digest + 4);
	putu32(md5data->buf[2], digest + 8);
	putu32(md5data->buf[3], digest + 12);
	ft_memset(md5data, 0, sizeof(t_md5));
}

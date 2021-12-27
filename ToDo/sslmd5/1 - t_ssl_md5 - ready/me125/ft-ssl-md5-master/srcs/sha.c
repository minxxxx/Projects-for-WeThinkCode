/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 09:07:27 by apakhomo          #+#    #+#             */
/*   Updated: 2018/02/03 09:07:28 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_sha256.h"

static void		bswapw(uint32_t *p, uint32_t i)
{
	while (i--)
		p[i] = (RR(p[i], 24) & 0x00ff00ff) | (RR(p[i], 8) & 0xff00ff00);
}

static void		rtrf(uint32_t *b, uint32_t *p, uint32_t i, uint32_t j)
{
	B(7, i) += (j ? (p[i & 15] += G1(P(i, 14)) + P(i, 9) +
			G0(P(i, 1))) : p[i & 15])
			+ g_s256[i + j] + S1(B(4, i))
			+ (B(6, i) ^ (B(4, i) & (B(5, i) ^ B(6, i))));
	B(3, i) += B(7, i);
	B(7, i) += S0(B(0, i)) +
		((B(0, i) & B(1, i)) | (B(2, i) & (B(0, i) ^ B(1, i))));
}

static void		hash(t_sha256 *data)
{
	int			i;
	uint32_t	b[8];
	uint32_t	*p;
	int			j;

	ft_memcpy(&b[0], data->hash, sizeof(uint32_t) * 8);
	p = data->buf;
	j = 0;
	while (j < 64)
	{
		i = -1;
		while (++i < 16)
			rtrf(b, p, i, j);
		j += 16;
	}
	i = -1;
	while (++i < 8)
		data->hash[i] += b[i];
}

void			sha256hash(t_sha256 *data, uint8_t *dat, uint32_t sz)
{
	uint32_t i;
	uint32_t l;
	uint32_t j;

	i = data->len[0] & 63;
	if ((data->len[0] += sz) < sz)
		++(data->len[1]);
	j = 0;
	l = 64 - i;
	while (sz >= l)
	{
		MEMCP((char*)data->buf + i, &dat[j], l);
		BSWP(data->buf, 16);
		hash(data);
		j += l;
		sz -= l;
		l = 64;
		i = 0;
	}
	MEMCP((char*)data->buf + i, &dat[j], sz);
}

void			sha256done(t_sha256 *data, uint8_t *buf, uint32_t i, uint32_t j)
{
	j = ((~i) & 3) << 3;
	BSWP(data->buf, (i + 3) >> 2);
	data->buf[i >> 2] &= 0xffffff80 << j;
	data->buf[i >> 2] |= 0x00000080 << j;
	if (i < 56)
		i = (i >> 2) + 1;
	else
	{
		if (i < 60)
			data->buf[15] ^= data->buf[15];
		else
			hash(data);
		i = (i < 60) ? i : 0;
	}
	while (i < 14)
		data->buf[i++] = 0;
	data->buf[14] = (data->len[1] << 3) | (data->len[0] >> 29);
	data->buf[15] = data->len[0] << 3;
	hash(data);
	i = -1;
	while (++i < 32)
	{
		data->buf[i % 16] = 0;
		buf[i] = (uint8_t)(data->hash[i >> 2] >> ((~i & 3) << 3));
	}
}

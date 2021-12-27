/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whirlpool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 09:07:27 by apakhomo          #+#    #+#             */
/*   Updated: 2018/02/03 09:07:28 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_whirlpool.h"
#include "ft_ssl_whirlpool_sbox.h"
#define RWH1 rwh(&l[0], k, 0, g_rc[twh->i])
#define RWH2 rwh(&l[twh->j], k, twh->j, 0)

void		rwh(uint64_t *b, uint64_t *a, int n, uint64_t c)
{
	*b = g_t[(a[n] >> 56) & 0xFF];
	*b ^= ROR64(g_t[(a[(n + 7) % 8] >> 48) & 0xFF], 8);
	*b ^= ROR64(g_t[(a[(n + 6) % 8] >> 40) & 0xFF], 16);
	*b ^= ROR64(g_t[(a[(n + 5) % 8] >> 32) & 0xFF], 24);
	*b ^= ROR64(g_t[(a[(n + 4) % 8] >> 24) & 0xFF], 32);
	*b ^= ROR64(g_t[(a[(n + 3) % 8] >> 16) & 0xFF], 40);
	*b ^= ROR64(g_t[(a[(n + 2) % 8] >> 8) & 0xFF], 48);
	*b ^= ROR64(g_t[a[(n + 1) % 8] & 0xFF], 56);
	*b ^= c;
}

uint64_t	swapwh64(uint64_t x)
{
	x = ((((uint64_t)(x) & 0x00000000000000FFULL) << 56) | \
		(((uint64_t)(x) & 0x000000000000FF00ULL) << 40) | \
		(((uint64_t)(x) & 0x0000000000FF0000ULL) << 24) | \
		(((uint64_t)(x) & 0x00000000FF000000ULL) << 8) | \
		(((uint64_t)(x) & 0x000000FF00000000ULL) >> 8) | \
		(((uint64_t)(x) & 0x0000FF0000000000ULL) >> 24) | \
		(((uint64_t)(x) & 0x00FF000000000000ULL) >> 40) | \
		(((uint64_t)(x) & 0xFF00000000000000ULL) >> 56));
	return (x);
}

void		whupdate(t_wh *twh, const void *data, size_t length)
{
	size_t n;

	while (length > 0)
	{
		n = MIN(length, 64 - twh->size);
		ft_memcpy(twh->x.buffer + twh->size, data, n);
		twh->size += n;
		twh->totalsize += n;
		data = (uint8_t*)data + n;
		length -= n;
		if (twh->size == 64)
		{
			whstep(twh, twh->x.x, twh->k, twh->l);
			twh->size = 0;
		}
	}
}

void		whfinal(t_wh *twh, uint8_t *digest)
{
	int			i;
	size_t		paddingsize;
	uint64_t	totalsize;

	totalsize = twh->totalsize * 8;
	if (twh->size < 32)
		paddingsize = 32 - twh->size;
	else
		paddingsize = 64 + 32 - twh->size;
	whupdate(twh, g_padding, paddingsize);
	twh->x.x[4] = 0;
	twh->x.x[5] = 0;
	twh->x.x[6] = 0;
	twh->x.x[7] = swapwh64(totalsize);
	whstep(twh, twh->x.x, twh->k, twh->l);
	i = -1;
	while (++i < 8)
		twh->h.h[i] = swapwh64(twh->h.h[i]);
	if (digest != NULL)
		ft_memcpy(digest, twh->h.digest, WHIRLPOOL_DIGEST_SIZE);
}

void		whstep(t_wh *twh, uint64_t *x, uint64_t *k, uint64_t *l)
{
	uint64_t *state;

	state = twh->state;
	twh->i = -1;
	while (++twh->i < 8)
		x[twh->i] = swapwh64(x[twh->i]);
	ft_memcpy(k, twh->h.h, sizeof(uint64_t) * 8);
	twh->i = -1;
	while (++twh->i < 8)
		state[twh->i] = x[twh->i] ^ k[twh->i];
	twh->i = -1;
	while (++twh->i < 10)
	{
		twh->j = -1;
		while (++twh->j < 8)
			(twh->j == 0) ? RWH1 : RWH2;
		ft_memcpy(k, l, sizeof(uint64_t) * 8);
		twh->j = -1;
		while (++twh->j < 8)
			rwh(&l[twh->j], state, twh->j, k[twh->j]);
		ft_memcpy(state, l, sizeof(uint64_t) * 8);
	}
	twh->i = -1;
	while (++twh->i < 8)
		twh->h.h[twh->i] ^= state[twh->i] ^ x[twh->i];
}

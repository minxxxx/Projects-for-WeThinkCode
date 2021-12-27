/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 13:49:20 by jtranchi          #+#    #+#             */
/*   Updated: 2018/08/28 17:34:58 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

unsigned int g_m[64] = {
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
	0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
	0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
	0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
	0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
	0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
	0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
	0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
	0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
	0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
	0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
	0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

t_mem			*padding_sha256(t_mem *mem)
{
	t_mem		*message;
	size_t		newlen;
	size_t		len;
	uint64_t	bitlen;

	message = (t_mem *)malloc(sizeof(t_mem));
	len = mem->len;
	bitlen = len * 8;
	newlen = len + 1;
	while (newlen % 64 != 56)
		newlen++;
	message->data = (unsigned char *)malloc(sizeof(unsigned char) * newlen);
	message->len = newlen;
	memcpy(message->data, mem->data, mem->len);
	message->data[len] = (unsigned char)128;
	while (++len <= newlen)
		message->data[len] = 0;
	bitlen = swap_uint64(bitlen);
	memcpy(message->data + newlen, &bitlen, 8);
	ft_free_mem(mem);
	return (message);
}

unsigned int	*get_tab(unsigned char *offset)
{
	int				i;
	unsigned int	*w;

	i = -1;
	w = (unsigned int *)malloc(sizeof(unsigned int) * 64);
	while (++i < 64)
	{
		if (i < 16)
			w[i] = (offset[i * 4] << 24) |
				(offset[i * 4 + 1] << 16) |
				(offset[i * 4 + 2] << 8) |
				(offset[i * 4 + 3]);
		else
			w[i] = D(w[i - 2]) + w[i - 7] + C(w[i - 15]) + w[i - 16];
	}
	return (w);
}

void			sha256_process(t_i *m, unsigned int *w, int i)
{
	(*m).t = (*m).h + B((*m).e) +
		CH((*m).e, (*m).f, (*m).g) + g_m[i] + w[i];
	(*m).t2 = A((*m).a) + MAJ((*m).a, (*m).b, (*m).c);
	(*m).h = (*m).g;
	(*m).g = (*m).f;
	(*m).f = (*m).e;
	(*m).e = (*m).d + (*m).t;
	(*m).d = (*m).c;
	(*m).c = (*m).b;
	(*m).b = (*m).a;
	(*m).a = (*m).t + (*m).t2;
}

void			hash_start(t_i *m, t_mem *mem, unsigned int *w)
{
	int i;

	i = -1;
	(*m).a = mem->h[0];
	(*m).b = mem->h[1];
	(*m).c = mem->h[2];
	(*m).d = mem->h[3];
	(*m).e = mem->h[4];
	(*m).f = mem->h[5];
	(*m).g = mem->h[6];
	(*m).h = mem->h[7];
	while (++i < 64)
		sha256_process(m, w, i);
}

void			hash_sha256(t_mem *mem, t_opt *opt)
{
	t_i				m;
	int				offset;
	unsigned int	*w;

	w = NULL;
	offset = 0;
	mem = padding_sha256(mem);
	init_mem(mem);
	while (offset < mem->len)
	{
		w = get_tab((mem->data + offset));
		hash_start(&m, mem, w);
		mem->h[0] += m.a;
		mem->h[1] += m.b;
		mem->h[2] += m.c;
		mem->h[3] += m.d;
		mem->h[4] += m.e;
		mem->h[5] += m.f;
		mem->h[6] += m.g;
		mem->h[7] += m.h;
		offset += 64;
	}
	print_output_sha256(mem, opt);
	ft_free_mem(mem);
}

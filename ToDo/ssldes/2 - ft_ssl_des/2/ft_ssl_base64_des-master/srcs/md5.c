/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 09:50:07 by jtranchi          #+#    #+#             */
/*   Updated: 2018/08/29 14:07:02 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

int32_t g_r[64] = {7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17,
	22, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 4, 11, 16, 23,
	4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 6, 10, 15, 21, 6, 10, 15, 21,
	6, 10, 15, 21, 6, 10, 15, 21};

int32_t g_k[64] = {
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};

t_mem	*padding_md5(t_mem *mem)
{
	t_mem		*message;
	size_t		newlen;
	size_t		len;
	uint32_t	bitlen;

	message = (t_mem *)malloc(sizeof(t_mem));
	message->h[0] = 0x67452301;
	message->h[1] = 0xefcdab89;
	message->h[2] = 0x98badcfe;
	message->h[3] = 0x10325476;
	len = mem->len;
	bitlen = len * 8;
	newlen = len + 1;
	while (newlen % 64 != 56)
		newlen++;
	message->data = (unsigned char *)ft_strnew(newlen + 64);
	message->len = newlen;
	memcpy(message->data, mem->data, mem->len);
	message->data[len] = (char)128;
	while (++len <= newlen)
		message->data[len] = 0;
	ft_memcpy(message->data + newlen, &bitlen, 4);
	ft_free_mem(mem);
	return (message);
}

void	md5_process(t_i *m, uint32_t *w, int i)
{
	if (i < 16)
		((*m).f = F((*m).b, (*m).c, (*m).d)) ?
			(*m).g = i : 0;
	else if (i < 32)
		((*m).f = G((*m).b, (*m).c, (*m).d)) ?
			((*m).g = (5 * i + 1) % 16) : 0;
	else if (i < 48)
		((*m).f = H((*m).b, (*m).c, (*m).d)) ?
			((*m).g = (3 * i + 5) % 16) : 0;
	else
		((*m).f = I((*m).b, (*m).c, (*m).d)) ?
			((*m).g = (7 * i) % 16) : 0;
	(*m).t = (*m).d;
	(*m).d = (*m).c;
	(*m).c = (*m).b;
	(*m).b = (*m).b +
		LEFTROTATE(((*m).a + (*m).f + g_k[i] + w[(*m).g]), g_r[i]);
	(*m).a = (*m).t;
}

void	hash_md5(t_mem *mem, t_opt *opt)
{
	int			offset;
	int			i;
	t_i			m;
	uint32_t	*w;

	mem = padding_md5(mem);
	offset = 0;
	while (offset < mem->len)
	{
		w = (uint32_t*)(mem->data + offset);
		m.a = mem->h[0];
		m.b = mem->h[1];
		m.c = mem->h[2];
		m.d = mem->h[3];
		i = -1;
		while (++i < 64)
			md5_process(&m, w, i);
		mem->h[0] += m.a;
		mem->h[1] += m.b;
		mem->h[2] += m.c;
		mem->h[3] += m.d;
		offset += 64;
	}
	print_output_md5(mem, opt);
	ft_free_mem(mem);
}

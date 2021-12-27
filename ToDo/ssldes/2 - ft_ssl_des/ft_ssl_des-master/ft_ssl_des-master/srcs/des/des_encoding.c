/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_encoding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:30:59 by jcamhi            #+#    #+#             */
/*   Updated: 2018/11/12 17:32:43 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

/*
	** Datalen is in bytes size.
*/

void		divide_block(uint8_t *out, t_uint48 in)
{
	uint64_t	in_x;
	uint64_t	mask;

	mask = 0x3F;
	in_x = in.x;
	in_x = end_conv_64(in_x) >> 16;
	ft_bzero(out, 8 * sizeof(char));
	out[0] = (in_x & (mask << 42)) >> 42;
	out[1] = (in_x & (mask << 36)) >> 36;
	out[2] = (in_x & (mask << 30)) >> 30;
	out[3] = (in_x & (mask << 24)) >> 24;
	out[4] = (in_x & (mask << 18)) >> 18;
	out[5] = (in_x & (mask << 12)) >> 12;
	out[6] = (in_x & (mask << 6)) >> 6;
	out[7] = (in_x & (mask << 0)) >> 0;
}

uint32_t	calculate_s_box_r(uint8_t blocks[8])
{
	uint32_t	s_box_r;
	int			z;

	s_box_r = 0;
	z = 0;
	while (z < 8)
	{
		s_box_r <<= 4;
		s_box_r |= compute_s_box(blocks[z], z);
		z++;
	}
	s_box_r = end_conv_32(s_box_r);
	return (s_box_r);
}

void		do_iteration(t_uint48 ks[16], uint32_t *l, uint32_t *r, size_t i)
{
	uint32_t	lp_rp_p[3];
	uint32_t	s_box_r;
	t_uint48	eed;
	t_uint48	xored;
	uint8_t		blocks[8];

	lp_rp_p[0] = *r;
	permutate((void*)r, (void*)&eed, g_des_e, 48);
	xored.x = eed.x ^ ks[i].x;
	divide_block(blocks, xored);
	s_box_r = calculate_s_box_r(blocks);
	permutate((void*)&s_box_r, (void*)&lp_rp_p[2], g_des_p, 32);
	lp_rp_p[1] = lp_rp_p[2] ^ *l;
	*l = lp_rp_p[0];
	*r = lp_rp_p[1];
}

uint64_t	encode_block(const uint64_t in, t_uint48 ks[16])
{
	uint64_t	out;
	uint32_t	l;
	uint32_t	r;
	int			i;

	permutate((const void*)&in, (void *)&out, g_des_ip, 64);
	l = *(uint32_t*)&out;
	r = *(((uint32_t*)&out) + 1);
	i = 0;
	while (i < 16)
	{
		do_iteration(ks, &l, &r, i);
		i++;
	}
	*(uint32_t*)&out = r;
	*((uint32_t*)&out + 1) = l;
	permutate((const void*)&out, (void *)&out, g_des_ip_inv, 64);
	return (out);
}

uint32_t	*des_encode(t_des *des, const uint8_t *data, size_t datalen,
	t_mode mode)
{
	size_t		n;
	uint64_t	*ret;
	uint64_t	*in;
	uint64_t	last_block;
	t_uint48	ks[16];

	if (mode == cbc)
		last_block = *(uint64_t*)des->iv;
	if (!(data = prepare_data(des, data, &datalen)) ||
		!(ret = prepare_ks_and_ret(des, ks, datalen)))
		return (NULL);
	in = (void*)data;
	n = 0;
	while (n < datalen / 8)
	{
		if (mode == cbc && des->encode == 1)
			in[n] ^= last_block;
		ret[n] = encode_block(in[n], ks);
		if (mode == cbc && des->encode == 1)
			last_block = ret[n];
		else if (mode == cbc && des->encode == 0)
			do_xor(ret, last_block, in, n);
		n++;
	}
	return (des_end(des, ret, datalen, data));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha1_compute_round.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:31:44 by jcamhi            #+#    #+#             */
/*   Updated: 2018/11/12 17:31:44 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

static uint32_t	f(uint32_t t, uint32_t b, uint32_t c, uint32_t d)
{
	if (t < 20)
		return ((b & c) | ((~b) & d));
	else if (t < 40)
		return (b ^ c ^ d);
	else if (t < 60)
		return ((b & c) | (b & d) | (c & d));
	else if (t < 80)
		return (b ^ c ^ d);
	else
	{
		ft_putstr_fd("ERROR 15\n", 2);
		return (-1);
	}
}

static void		do_iteration(uint32_t abcde[5], uint32_t t, uint32_t w[80],
	const uint32_t k[80])
{
	uint32_t	temp;

	temp = rotl(5, abcde[0]) + f(t, abcde[1], abcde[2], abcde[3])
		+ abcde[4] + w[t] + k[t];
	abcde[4] = abcde[3];
	abcde[3] = abcde[2];
	abcde[2] = rotl(30, abcde[1]);
	abcde[1] = abcde[0];
	abcde[0] = temp;
}

static void		add_h_abcde(uint32_t h[5], uint32_t abcde[5])
{
	h[0] = h[0] + abcde[0];
	h[1] = h[1] + abcde[1];
	h[2] = h[2] + abcde[2];
	h[3] = h[3] + abcde[3];
	h[4] = h[4] + abcde[4];
}

void			compute_round(uint32_t h[5], const uint32_t k[80],
	const void *m)
{
	uint32_t	w[80];
	uint32_t	t;
	uint32_t	abcde[5];

	t = 0;
	while (t < 16)
	{
		w[t] = end_conv_32(((uint32_t*)m)[t]);
		t++;
	}
	t = 16;
	while (t < 80)
	{
		w[t] = rotl(1, w[t - 3] ^ w[t - 8] ^ w[t - 14] ^ w[t - 16]);
		t++;
	}
	ft_memcpy(abcde, h, 5 * sizeof(uint32_t));
	t = 0;
	while (t < 80)
	{
		do_iteration(abcde, t, w, k);
		t++;
	}
	add_h_abcde(h, abcde);
}
